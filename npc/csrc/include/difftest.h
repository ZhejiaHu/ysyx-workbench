#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

#include <cassert>
#include <ios>
#include <string>

#include "common.h"
#include <dlfcn.h>

#define DIFFTEST_PORT 1234

void (*ref_difftest_memcpy)(paddr_t addr, void* buf, size_t n, bool direction) = nullptr;
void (*ref_difftest_regcpy)(void *dut, bool direction) = nullptr;
void (*ref_difftest_exec)(uint64_t n) = nullptr;
void (*ref_difftest_raise_intr)(word_t NO) = nullptr;
void (*ref_difftest_init)(int port) = nullptr;



void init_difftest(const std::unique_ptr<VTop>& vtop, const std::string& ref_so_file, const uint8_t* pmem, const std::streamsize& img_size) {
	void* handle = dlopen(ref_so_file.c_str(), RTLD_LAZY); assert(handle);
	ref_difftest_memcpy = (void (*)	(paddr_t, void*, size_t, bool)) dlsym(handle, "difftest_memcpy"); assert(ref_difftest_memcpy);
	ref_difftest_regcpy = (void (*) (void*, bool)) dlsym(handle, "difftest_regcpy"); assert(ref_difftest_regcpy);
	ref_difftest_exec = (void (*) (uint64_t)) dlsym(handle, "difftest_exec"); assert(ref_difftest_exec);
	ref_difftest_raise_intr = (void (*) (word_t)) dlsym(handle, "difftest_raise_intr"); assert(ref_difftest_raise_intr);
	ref_difftest_init = (void (*) (int)) dlsym(handle, "difftest_init"); assert(ref_difftest_init);
	
	std::cout << "[difftest.h : init_difftest] Initialisatiation of Reference program." << std::endl;
	ref_difftest_init(DIFFTEST_PORT);
	ref_difftest_memcpy(SIM_MBASE, guest_to_host(SIM_MBASE), img_size, true);
	word_t init_regs[33];
	get_all_registers(vtop, init_regs, true);
	ref_difftest_regcpy((unsigned char *) init_regs, true);
}


void difftest_and_compare_once(const std::unique_ptr<VTop>& vtop) {
	ref_difftest_exec(1);
	word_t ref_regs[33];
	ref_difftest_regcpy(ref_regs, false);
	printf("[difftest.h : difftest_and_compare_once] Example register 15 --- dut : %08x | ref : %08x\n", get_register(vtop, 15), ref_regs[15]);
	for (int i = 0; i < 32; i++) if (get_register(vtop, i) != ref_regs[i]) {
		printf("[difftest.h : difftest_and_compare_once] Different register value of register %d --- dut : %08x | ref : %08x\n", i, get_register(vtop, i), ref_regs[i]); 
		assert(0);
	}
	if (get_pc() != ref_regs[32]) {
		printf("[difftest.h : difftest_and_compare_once] Different register value of pc --- dut : %08x | ref : %08x\n", pc_read(), ref_regs[32]);
	}
}

#endif