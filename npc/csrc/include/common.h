#ifndef __COMMON_H__
#define __COMMON_H__

#include <algorithm>
#include <array>
#include <cinttypes>
#include <memory>
#include <string>
#include "debug.h"


#include "VTop.h"
#include "VTop__Dpi.h"
#include "VTop__Syms.h"
#include "svdpi.h"  
#include "verilated.h"
#include "VTop___024root.h"

typedef uint32_t paddr_t;
typedef uint32_t word_t; 

#define PG_ALIGN __attribute((aligned(4096)))

#define INST_SIZE 4
#define SIM_MBASE 0x80000000
#define SIM_MSIZE 0x8000000
#define DEFAULT_IMG_SIZE 44 

static uint8_t pmem[SIM_MSIZE] PG_ALIGN;


static inline word_t host_read(void* addr, int len) {
    switch (len) {
        case 1: return *(uint8_t *) addr;
        case 2: return *(uint16_t *) addr;
        case 4: return *(uint32_t *) addr;
    }
	return 0;
}


static inline void host_write(void* addr, int len, word_t data) {
	switch (len) {
		case 1: *(uint8_t *) addr = data; return;
		case 2: *(uint16_t *) addr = data; return;
		case 4: *(uint32_t *) addr = data; return; 
	}
}


static inline uint8_t* guest_to_host(paddr_t paddr) {
    return pmem + paddr - SIM_MBASE;
}


static inline bool check_pmem_boundary(uint8_t* host_ptr) {
    return host_ptr >= pmem && host_ptr < pmem + SIM_MSIZE;
}


int pmem_read(int raddr) {
	uint8_t* host_ptr = pmem + static_cast<paddr_t>(raddr & ~0x3u) - SIM_MBASE;
	word_t value = host_read(host_ptr, 4);
	// printf("[pmem_read] raddr --- 0x%x | value --- 0x%x\n", raddr, value);
	return value;
}


void pmem_write(int waddr, int wdata_, char wmask) {
	uint32_t wdata = static_cast<uint32_t>(wdata_);
	uint8_t* host_ptr = pmem + static_cast<paddr_t>(waddr & ~0x3u) - SIM_MBASE;
	// printf("[pmem_write] waddr --- 0x%x | wdata : 0x%x | wmask : 0x%x\n", waddr, wdata, wmask);
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		if ((wmask >> i) & 0x1) *(host_ptr + i) = static_cast<uint8_t>(wdata >> (idx++ * 8) & 0xFF);
	}
}


std::array<std::string, 32> reg_names = {
  "zero", "ra", "tp", "sp", "a0", "a1", "a2", "a3",
  "a4", "a5", "a6", "a7", "t0", "t1", "t2", "t3",
  "t4", "t5", "t6", "t7", "t8", "rs", "fp", "s0",
  "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8"
};


#define GET_REGISTER(N) vtop->rootp->concat2(Top__DOT__datapath__DOT__reg_file__DOT__regs_, N)
#define PRINT_REGISTER(N) Log("Register %d : 0x%08" PRIx32, N, GET_REGISTER(N))


int print_all_registers(const std::unique_ptr<VTop>& vtop) {
	PRINT_REGISTER(0);
	PRINT_REGISTER(1);
	PRINT_REGISTER(2);
	PRINT_REGISTER(3);
	PRINT_REGISTER(4);
	PRINT_REGISTER(5);
	PRINT_REGISTER(6);
	PRINT_REGISTER(7);
	PRINT_REGISTER(8);
	PRINT_REGISTER(9);
	PRINT_REGISTER(10);
	PRINT_REGISTER(11);
	PRINT_REGISTER(12);
	PRINT_REGISTER(13);
	PRINT_REGISTER(14);
	PRINT_REGISTER(15);
	PRINT_REGISTER(16);
	PRINT_REGISTER(17);
	PRINT_REGISTER(18);
	PRINT_REGISTER(19);
	PRINT_REGISTER(20);
	PRINT_REGISTER(21);
	PRINT_REGISTER(22);
	PRINT_REGISTER(23);
	PRINT_REGISTER(24);
	PRINT_REGISTER(25);
	PRINT_REGISTER(26);
	PRINT_REGISTER(27);
	PRINT_REGISTER(28);
	PRINT_REGISTER(29);
	PRINT_REGISTER(30);
	PRINT_REGISTER(31);
	return 0;
}

int print_register(const std::unique_ptr<VTop>& vtop, int idx) {
	if (idx < 0 || idx >= 32) return -1;
	switch (idx) {
		case 0: PRINT_REGISTER(0); break;
		case 1: PRINT_REGISTER(1); break;
		case 2: PRINT_REGISTER(2); break;
		case 3: PRINT_REGISTER(3); break;
		case 4: PRINT_REGISTER(4); break;
		case 5: PRINT_REGISTER(5); break;
		case 6: PRINT_REGISTER(6); break;
		case 7: PRINT_REGISTER(7); break;
		case 8: PRINT_REGISTER(8); break;
		case 9: PRINT_REGISTER(9); break;
		case 10: PRINT_REGISTER(10); break;
		case 11: PRINT_REGISTER(11); break;
		case 12: PRINT_REGISTER(12); break;
		case 13: PRINT_REGISTER(13); break;
		case 14: PRINT_REGISTER(14); break;
		case 15: PRINT_REGISTER(15); break;
		case 16: PRINT_REGISTER(16); break;
		case 17: PRINT_REGISTER(17); break;
		case 18: PRINT_REGISTER(18); break;
		case 19: PRINT_REGISTER(19); break;
		case 20: PRINT_REGISTER(20); break;
		case 21: PRINT_REGISTER(21); break;
		case 22: PRINT_REGISTER(22); break;
		case 23: PRINT_REGISTER(23); break;
		case 24: PRINT_REGISTER(24); break;
		case 25: PRINT_REGISTER(25); break;
		case 26: PRINT_REGISTER(26); break;
		case 27: PRINT_REGISTER(27); break;
		case 28: PRINT_REGISTER(28); break;
		case 29: PRINT_REGISTER(29); break;
		case 30: PRINT_REGISTER(30); break;
		case 31: PRINT_REGISTER(31); break;
	}
	return 0;
}

word_t get_register(const std::unique_ptr<VTop>& vtop, int idx) {
	switch (idx) {
		case 0: return GET_REGISTER(0); 
		case 1: return GET_REGISTER(1); 
		case 2: return GET_REGISTER(2); 
		case 3: return GET_REGISTER(3); 
		case 4: return GET_REGISTER(4); 
		case 5: return GET_REGISTER(5); 
		case 6: return GET_REGISTER(6); 
		case 7: return GET_REGISTER(7); 
		case 8: return GET_REGISTER(8); 
		case 9: return GET_REGISTER(9); 
		case 10: return GET_REGISTER(10); 
		case 11: return GET_REGISTER(11); 
		case 12: return GET_REGISTER(12); 
		case 13: return GET_REGISTER(13); 
		case 14: return GET_REGISTER(14); 
		case 15: return GET_REGISTER(15); 
		case 16: return GET_REGISTER(16); 
		case 17: return GET_REGISTER(17); 
		case 18: return GET_REGISTER(18); 
		case 19: return GET_REGISTER(19); 
		case 20: return GET_REGISTER(20); 
		case 21: return GET_REGISTER(21); 
		case 22: return GET_REGISTER(22); 
		case 23: return GET_REGISTER(23); 
		case 24: return GET_REGISTER(24); 
		case 25: return GET_REGISTER(25); 
		case 26: return GET_REGISTER(26); 
		case 27: return GET_REGISTER(27); 
		case 28: return GET_REGISTER(28); 
		case 29: return GET_REGISTER(29); 
		case 30: return GET_REGISTER(30); 
		case 31: return GET_REGISTER(31);
	}
	return 0;
}


word_t get_pc() {
	Verilated::dpiScope(Verilated::scopeFind("VTop.Top.inst_memory"));
	return VTop::pc_read();
} 


void get_all_registers(const std::unique_ptr<VTop>& vtop, word_t* dst, bool include_pc) {
	for (int i = 0; i < 32; i++) *(dst + i) = get_register(vtop, i);
	if (include_pc) *(dst + 32) = get_pc();
}

bool valid_register_name(const std::string& reg_name) {
	auto reg_ptr = find(reg_names.begin(), reg_names.end(), reg_name);
	return reg_ptr != reg_names.end();
}

int print_register(const std::unique_ptr<VTop>& vtop, const std::string& reg_name) {
	auto reg_ptr = find(reg_names.begin(), reg_names.end(), reg_name);
	return print_register(vtop, reg_ptr - reg_names.begin());
}

int get_register(const std::unique_ptr<VTop>& vtop, const std::string& reg_name) {
	auto reg_ptr = find(reg_names.begin(), reg_names.end(), reg_name);
	return get_register(vtop, reg_ptr - reg_names.begin());
}


#endif