#include <cassert>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <regex>
#include <sstream>
#include <utility>
#include <vector>
#include <getopt.h>


#include "VTop.h"
#include "VTop__Dpi.h"
#include "VTop__Syms.h"
#include "svdpi.h"  
#include "verilated.h"
#include "verilated_vcd_c.h"

#include "include/common.h"
#include "include/debug.h"
#include "include/expr.h"
#include "include/trace.h"
#include "include/difftest.h"

bool batch_mode = false;
bool itrace_mode = false;
bool mtrace_mode = false;
bool ftrace_mode = false;
bool difftest_mode = true;



#define ITRACE(pc, code) {if (itrace_mode) itrace((pc), (code));}
#define FTRACE(pc, code, vtop) {if (ftrace_mode) ftrace((vtop), (pc), (code));}
#define TRACE(pc, code, vtop) {ITRACE((pc), (code)); FTRACE((pc), (code), (vtop));}
#define DIFFTEST_ONCE {if (difftest_mode) difftest_and_compare_once(vtop);}

static std::string img_path;
static std::string elf_path;
static std::string ref_so_path;
static std::streamsize img_size;

static void parse_args(int argc, char** argv) {
    const char* const shortcuts = "i:e:d:";
    const option opts[] = {
        {"image_path", required_argument, nullptr, 'i'},
		{"elf_path", required_argument, nullptr, 'e'},
		{"nemu_so_path", required_argument, nullptr, 'd'}
    };
    while (true) {
        const auto opt = getopt_long(argc, argv, shortcuts, opts, nullptr);
        if (opt == -1) break;
        switch (opt) {
            case 'i': img_path = std::string(optarg); break;
			case 'e': elf_path = std::string(optarg); std::cout<<elf_path<<std::endl; break;
			case 'd': ref_so_path = std::string(optarg); std::cout<<ref_so_path<<std::endl; break;
            default: std::cout << "[main.cpp : parse_args] Unknown options is given in command line " << std::string(optarg) << std::endl;
        }
    }
}


static void load_image() {
    if (img_path == "") {
        std::cout << "[main.cpp : load_image] Using default image." << std::endl;
        return;
    }
    std::cout << "[main.cpp : load_image] Loading image from path " << img_path << std::endl;
    std::ifstream img_file(img_path, std::ios::binary | std::ios::ate);
    assert(img_file);
    img_size = img_file.tellg();
    assert(img_size < SIM_MSIZE);
    img_file.seekg(0, std::ios::beg);
    std::vector<char> buf(img_size);
    assert(img_file.read(buf.data(), img_size));
    std::copy(buf.begin(), buf.end(), guest_to_host(SIM_MBASE));
    printf("[main.cpp : load_image] Loading image is successful.\n");
}

void setup_trace() {
	if (itrace_mode) init_disasm("riscv32-pc-linux-gnu");
	init_trace(itrace_mode, mtrace_mode, ftrace_mode, elf_path);
}

bool finish = false;


void terminate_simulation(char exit, int pc) {
    finish = true;
	Log("npc: %s at pc = 0x%08" PRIx32, (exit == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED)), static_cast<paddr_t>(pc));
    if (exit) throw std::runtime_error("[terminate_simulation.c : terminate_simulation] Test case fails!");
	else printf("[terminate_simulation.c : terminate_simulation] Simulation terminated.\n");
}


void execute_once(const std::unique_ptr<VerilatedContext>& contextp, const std::unique_ptr<VTop>& vtop, VerilatedVcdC* tfp, int& idx) {
	idx++;
    vtop->clock = !vtop->clock; 
	printf("[Index: %d: input] ---------------Begin-----------------------------------------------\n", idx);
	std::cout << "Current scope (top module): " << Verilated::dpiScope() << std::endl;
	paddr_t cur_pc = get_pc();
	word_t cur_inst = host_read(guest_to_host(cur_pc), 4);
	Log("[Simulation] pc = 0x%08" PRIx32 " | inst = 0x%08" PRIx32, cur_pc, cur_inst);
	TRACE(cur_pc, cur_inst, vtop);
	vtop->eval();
	printf("[Index: %d: input] ---------------End-------------------------------------------------\n\n", idx);
	tfp->dump(contextp->time());
	contextp->timeInc(1);
	vtop->clock = !vtop->clock; 
    vtop->eval();
    tfp->dump(contextp->time());
	contextp->timeInc(1);
	contextp->gotFinish(finish);
	DIFFTEST_ONCE
}

int command_c(const std::string& args, const std::unique_ptr<VerilatedContext>& contextp, const std::unique_ptr<VTop>& vtop, VerilatedVcdC* tfp, int& idx) {
	while (!contextp->gotFinish()) execute_once(contextp, vtop, tfp, idx);
	return 0;
}

int command_q(const std::string& args, const std::unique_ptr<VerilatedContext>& contextp, const std::unique_ptr<VTop>& vtop, VerilatedVcdC* tfp, int& idx) {
	finish = true;
	Log("npc: %s", ANSI_FMT("Quit during execution.", ANSI_BG_RED));
	return -1;
}

int command_si(const std::string& args, const std::unique_ptr<VerilatedContext>& contextp, const std::unique_ptr<VTop>& vtop, VerilatedVcdC* tfp, int& idx) {
	std::regex pattern(R"(si\s*(\d+)?)");
	std::smatch match;
	if (std::regex_match(args, match, pattern)) {
		for (int i = 0; i < (match[1].matched ? (std::stoi(match[1].str())) : 1); i++) execute_once(contextp, vtop, tfp, idx);
	} else return -1;
	return 0;
}

int command_r(const std::string& args, const std::unique_ptr<VerilatedContext>& contextp, const std::unique_ptr<VTop>& vtop, VerilatedVcdC* tfp, int& idx) {
	std::regex pattern(R"(r\s*(\d+|[a-z0-9]+))");
	std::smatch match;
	if (std::regex_match(args, match, pattern)) {
		if (match[1].matched) {
			try {return print_register(vtop, std::stoi(match[1].str()));}
			catch (const std::invalid_argument&) {return print_register(vtop, match[1].str());}
		} else print_all_registers(vtop);
	} else return -1;
	return 0;
}

int command_eval(const std::string& args, const std::unique_ptr<VerilatedContext>& contextp, const std::unique_ptr<VTop>& vtop, VerilatedVcdC* tfp, int& idx) {
	std::regex pattern(R"(eval\s*([a-z0-9+\s\-*/().]+))");
	std::smatch match;
	if (std::regex_match(args, match, pattern)) {
		if (match[1].matched) {
			return expression(match[1].str(), vtop);
		} else {
			std::cout << "[main.cpp : command_eval] Ungiven arithmatic expressions." << std::endl;
			return 0;
		}
	}
	return 0;
}

std::map<std::string, std::pair<std::string, std::function<int(const std::string&, const std::unique_ptr<VerilatedContext>&, const std::unique_ptr<VTop>&, VerilatedVcdC*, int&)>>> command_table = {
	{"c", {"Continue the execution of the program", command_c}},
	{"q", {"Exit NPC", command_q}},
	{"si", {"Execute target number of steps (default 1 step)", command_si}},
	{"r", {"Show the values in all registers", command_r}},
	{"eval", {"Evaluate given simple arithmatic expression", command_eval}}
};


void setup_tools(const std::unique_ptr<VTop>& vtop) {
	setup_trace();
	init_difftest(vtop, ref_so_path, pmem, img_size);
}

int main(int argc, char** argv) {
    parse_args(argc, argv);
    load_image();
    Verilated::mkdir("logs");
    const std::unique_ptr<VerilatedContext> contextp {new VerilatedContext};
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);
    const std::unique_ptr<VTop> vtop {new VTop{contextp.get(), "VTop"}};
    VerilatedVcdC* tfp = new VerilatedVcdC;
    vtop->trace(tfp, 99);
    tfp->open("logs/VTop.vcd");    
    vtop->reset = 1, vtop->clock = 0;
    for (int i = 0; i < 10; i++) {
        contextp->timeInc(1);
        vtop->clock = !vtop->clock; 
        vtop->eval();
        tfp->dump(contextp->time());
    }
	vtop->reset = 0;
	setup_tools(vtop);
	int idx = 0;
	if (batch_mode) while (!contextp->gotFinish()) {
		idx++;
        vtop->clock = !vtop->clock; 
		printf("[Index: %d: input] ---------------Begin-----------------------------------------------\n", idx);
        vtop->eval();
		printf("[Index: %d: input] ---------------End-------------------------------------------------\n\n", idx);
		tfp->dump(contextp->time());
		contextp->timeInc(1);

		vtop->clock = !vtop->clock; 
        vtop->eval();
		tfp->dump(contextp->time());
		contextp->timeInc(1);
		contextp->gotFinish(finish);
	} else {
		std::string command, first_token;
    	while (!contextp->gotFinish()) {
			std::cout << "Enter a command (c, q, si, r, eval): ";
			std::getline(std::cin, command);
			std::istringstream iss(command);
			iss >> first_token;
			int result = 0;
			if (command_table.find(first_token) != command_table.end()) result = command_table[first_token].second(command, contextp, vtop, tfp, idx);
			else std::cout << "Undefined command: " << first_token << std::endl; 
			if (result < 0) {
				Log("npc: %s", ANSI_FMT("Quit during execution.", ANSI_BG_RED));
				break;
			}
    	}
	}
	
    tfp->close();
	close_trace(itrace_mode, mtrace_mode, ftrace_mode);
    printf("[main.cpp : main] Termination has ended.\n");
    return 0;
}
