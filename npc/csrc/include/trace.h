#ifndef __TRACE_H__
#define __TRACE_H__

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCInstPrinter.h"
#if LLVM_VERSION_MAJOR >= 14
#include "llvm/MC/TargetRegistry.h"
#if LLVM_VERSION_MAJOR >= 15
#include "llvm/MC/MCSubtargetInfo.h"
#endif
#else
#include "llvm/Support/TargetRegistry.h"
#endif
#include "llvm/Support/TargetSelect.h"

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

#if LLVM_VERSION_MAJOR < 11
#error Please use LLVM with major version >= 11
#endif

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <memory>
#include <stack>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <elf.h>
#include "common.h"
#include "debug.h"
#include "VTop___024root.h"

#define HEX(val) "0x" << std::hex << std::setw(8) << std::setfill('0') << (val)
#define PRINT_FUNC_CALL(fn_name, pc, jump_pc, recur_depth) ftrace_logfile << HEX(pc) << ":" << std::string((recur_depth), ' ') << "call [" << (fn_name) << "@" << HEX(jump_pc) << "]" << std::endl;
#define PRINT_RET(fn_name, pc, jump_pc, recur_depth) ftrace_logfile << HEX(pc) << ":" << std::string((recur_depth + 1), ' ') << "ret [" << (fn_name) << "@" << HEX(jump_pc) << "]" << std::endl;
#define RS1(code) static_cast<uint32_t>(((code) >> 15) & ((1 << 5) - 1))
#define IMMI(code) SEXT(BITS(code, 31, 20), 12)
#define IMMJ(code) SEXT((BITS(code, 31, 31) << 20) | (BITS(code, 19, 12) << 12) | (BITS(code, 20, 20) << 11) | (BITS(code, 30, 21) << 1), 21)
#define READ_SUCCESS assert(elf_file.good());
#define ISRET(code) ((code) == 0x00008067)

static llvm::MCDisassembler *gDisassembler = nullptr;
static llvm::MCSubtargetInfo *gSTI = nullptr;
static llvm::MCInstPrinter *gIP = nullptr;

static std::ofstream itrace_logfile;
static std::ofstream mtrace_logfile;
static std::ofstream ftrace_logfile;
static std::ifstream elf_file;

static std::vector<std::tuple<std::string, uint32_t, uint32_t>> func_list;
static std::stack<std::tuple<std::string, uint32_t, uint32_t>> fncall_stack;
static uint32_t recur_depth = 0;

static std::unique_ptr<char[]> read_section_header_table(std::unique_ptr<Elf32_Shdr[]>& shtable, Elf32_Off& shoff, uint16_t& shnum, uint16_t& shentsize, uint16_t& shstrndx) {
	elf_file.seekg(shoff, std::ios::beg);
	elf_file.read(reinterpret_cast<char*>(shtable.get()), shnum * shentsize);
	elf_file.seekg(shtable[shstrndx].sh_offset, std::ios::beg);
	std::unique_ptr<char[]> shstr = std::make_unique<char[]>(shtable[shstrndx].sh_size);
	elf_file.read(shstr.get(), shtable[shstrndx].sh_size);
	return shstr;
}

static std::tuple<std::unique_ptr<Elf32_Sym[]>, std::unique_ptr<char[]>, uint32_t> find_sym_str_table(std::unique_ptr<Elf32_Shdr[]>& shtable, std::unique_ptr<char[]>& shstr, uint16_t& shnum) {
	std::unique_ptr<Elf32_Sym[]> symtable;
	std::unique_ptr<char[]> strtable;
	bool find_sym = false, find_str = false;
	int idx = 0; uint32_t entnum;
	for (int i = 0; i < shnum; i++) {
		if (!find_sym && shtable[i].sh_type == SHT_SYMTAB) {
			entnum = shtable[i].sh_size / shtable[i].sh_entsize;
			symtable = std::make_unique<Elf32_Sym[]>(entnum);
			elf_file.seekg(shtable[i].sh_offset, std::ios::beg);
			elf_file.read(reinterpret_cast<char*>(symtable.get()), shtable[i].sh_size);
			assert(elf_file.good());
			find_sym = true;
		}
		if (!find_str && shtable[i].sh_type == SHT_STRTAB) {
			char* sh_name = shstr.get() + shtable[i].sh_name; 
			if (!std::strcmp(sh_name, ".strtab")) {
				strtable = std::make_unique<char[]>(shtable[i].sh_size);
				elf_file.seekg(shtable[i].sh_offset, std::ios::beg);
				elf_file.read(strtable.get(), shtable[i].sh_size);
				assert(elf_file.good());
				find_str = true;
			}
		}
		if (find_sym && find_str) break;
	}
	assert(find_sym && find_str);
	return {std::move(symtable), std::move(strtable), entnum};
}


static void find_functions(std::unique_ptr<Elf32_Sym[]>& symtable, std::unique_ptr<char[]>& strtable, uint32_t entnum) {
	for (int i = 0; i < entnum; i++) {
		if (ELF32_ST_TYPE(symtable[i].st_info) == STT_FUNC) {
			func_list.push_back({std::string(strtable.get() + symtable[i].st_name), symtable[i].st_value, symtable[i].st_size});
		}
	}
	std::sort(func_list.begin(), func_list.end(), [] (const std::tuple<std::string, uint32_t, uint32_t>& fn1, std::tuple<std::string, uint32_t, uint32_t>& fn2) {return std::get<1>(fn1) < std::get<1>(fn2);});
}

static void print_functions() {
	assert(func_list.size());
	std::cout << "[trace.h : print_functions] Printing find functions." << std::endl;
	int idx = 0;
	for (const std::tuple<std::string, uint32_t, uint32_t>& fn : func_list) {
		idx++;
		printf("Function %d --- name : %s, address : 0x%x, size : 0x%x\n", idx, std::get<0>(fn).c_str(), std::get<1>(fn), std::get<2>(fn));
	}
}

static void preprocessing() {
	if(!elf_file) std::runtime_error("[trace.h: preprocessing] Elf file does not open.");
	elf_file.seekg(0, std::ios::beg);
	std::unique_ptr<Elf32_Ehdr> elf_header = std::make_unique<Elf32_Ehdr>();
	elf_file.read(reinterpret_cast<char*>(elf_header.get()), sizeof(Elf32_Ehdr));
	READ_SUCCESS
	Elf32_Off shoff = elf_header->e_shoff;
	uint16_t shnum = elf_header->e_shnum, shentsize = elf_header->e_shentsize, shstrndx = elf_header->e_shstrndx;
	std::unique_ptr<Elf32_Shdr[]> shtable = std::make_unique<Elf32_Shdr[]>(shnum);	
	std::unique_ptr<char[]> shstr = read_section_header_table(shtable, shoff, shnum, shentsize, shstrndx);
	std::tuple<std::unique_ptr<Elf32_Sym[]>, std::unique_ptr<char[]>, uint32_t> symstr = find_sym_str_table(shtable, shstr, shnum);
	std::unique_ptr<Elf32_Sym[]> symtable = std::move(std::get<0>(symstr));
	std::unique_ptr<char[]> strtable = std::move(std::get<1>(symstr));
	find_functions(symtable, strtable, std::get<2>(symstr));
	print_functions();
}


void init_trace(bool itrace_on, bool mtrace_on, bool ftrace_on, std::string& elf_path) {
	if (itrace_on) itrace_logfile.open("trace/itrace.txt");
	if (mtrace_on) mtrace_logfile.open("trace/mtrace.txt");
	if (ftrace_on) ftrace_logfile.open("trace/ftrace.txt"), elf_file.open(elf_path, std::ios::binary), preprocessing();
}


void close_trace(bool itrace_on, bool mtrace_on, bool ftrace_on) {
	if (itrace_on) itrace_logfile.close();
	if (mtrace_on) mtrace_logfile.close();
	if (ftrace_on) ftrace_logfile.close(), elf_file.close();
}


void init_disasm(const std::string triple) {
  llvm::InitializeAllTargetInfos();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmParsers();
  llvm::InitializeAllDisassemblers();

  std::string errstr;
  std::string gTriple(triple);

  llvm::MCInstrInfo *gMII = nullptr;
  llvm::MCRegisterInfo *gMRI = nullptr;
  auto target = llvm::TargetRegistry::lookupTarget(gTriple, errstr);
  if (!target) {
    llvm::errs() << "Can't find target for " << gTriple << ": " << errstr << "\n";
    assert(0);
  }

  llvm::MCTargetOptions MCOptions;
  gSTI = target->createMCSubtargetInfo(gTriple, "", "");
  std::string isa = target->getName();
  if (isa == "riscv32" || isa == "riscv64") {
    gSTI->ApplyFeatureFlag("+m");
    gSTI->ApplyFeatureFlag("+a");
    gSTI->ApplyFeatureFlag("+c");
    gSTI->ApplyFeatureFlag("+f");
    gSTI->ApplyFeatureFlag("+d");
  }
  gMII = target->createMCInstrInfo();
  gMRI = target->createMCRegInfo(gTriple);
  auto AsmInfo = target->createMCAsmInfo(*gMRI, gTriple, MCOptions);
#if LLVM_VERSION_MAJOR >= 13
   auto llvmTripleTwine = llvm::Twine(triple);
   auto llvmtriple = llvm::Triple(llvmTripleTwine);
   auto Ctx = new llvm::MCContext(llvmtriple,AsmInfo, gMRI, nullptr);
#else
   auto Ctx = new llvm::MCContext(AsmInfo, gMRI, nullptr);
#endif
  gDisassembler = target->createMCDisassembler(*gSTI, *Ctx);
  gIP = target->createMCInstPrinter(llvm::Triple(gTriple),
      AsmInfo->getAssemblerDialect(), *AsmInfo, *gMII, *gMRI);
  gIP->setPrintImmHex(true);
  gIP->setPrintBranchImmAsAddress(true);
  if (isa == "riscv32" || isa == "riscv64")
    gIP->applyTargetSpecificCLOption("no-aliases");
}


std::string disassemble(uint32_t pc, uint32_t code) {
  llvm::MCInst inst;
  llvm::ArrayRef<uint8_t> arr(reinterpret_cast<uint8_t*>(&code), 4);
  uint64_t dummy_size = 0;
  gDisassembler->getInstruction(inst, dummy_size, arr, pc, llvm::nulls());
  std::string s;
  llvm::raw_string_ostream os(s);
  gIP->printInst(&inst, pc, "", *gSTI, os);
  return s.substr(s.find_first_not_of('\t'));
}


void itrace(uint32_t pc, uint32_t code) {
	std::string decoded = disassemble(pc, code);
	assert(itrace_logfile.is_open());
	itrace_logfile << HEX(pc) << " | " << HEX(code) << " : " << decoded << std::endl;
}


void ftrace(const std::unique_ptr<VTop>& vtop, uint32_t pc, uint32_t code) {
	uint32_t opcode = code & ((1 << 7) - 1);
	bool jal = opcode == 0b1101111, jalr = opcode == 0b1100111;
	if (!jal && !jalr) return;
	uint32_t jump_pc = (jal ? pc : get_register(vtop, RS1(code))) + (jal ? IMMJ(code) : IMMI(code));
	auto ptr = std::lower_bound(func_list.begin(), func_list.end(), jump_pc, [] (const std::tuple<std::string, uint32_t, uint32_t>& fn, uint32_t val) {return std::get<1>(fn) < val;});
	if (ISRET(code)) {
		if (ptr == func_list.begin()) throw std::runtime_error("[trace.h: ftrace] Jump back to unknown function.");
		std::string fn_name = std::get<0>(*std::prev(ptr));
		while (!fncall_stack.empty() && std::get<0>(fncall_stack.top()) != fn_name) fncall_stack.pop(), recur_depth--;
		PRINT_RET(fn_name, pc, jump_pc, recur_depth);
	} else {
		if (ptr == func_list.end() || std::get<1>(*ptr) != jump_pc) {
			std::cout << "[trace.h : ftrace] Error --- pc : " << HEX(pc) << " | code : " << HEX(code) << " | jump_pc : " << HEX(jump_pc) << std::endl;
			throw std::runtime_error("[trace.h : ftrace] Jump to address without corresponding known function name.");
		}
		std::string fn_name = std::get<0>(*ptr);
		recur_depth++;
		fncall_stack.push({fn_name, jump_pc, recur_depth});
		PRINT_FUNC_CALL(fn_name, pc, jump_pc, recur_depth);
	}  
}	

#endif