/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

#if defined(CONFIG_ISA_riscv)
#define WORD_SIZE 4 
#define WORD_SHIFT 2
#define OFFSET(addr, i) ((addr) + ((i) << WORD_SHIFT))
#endif


__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
	size_t num_word = n >> WORD_SHIFT;
	for (int i = 0; i < num_word; i++) {
		if (direction == DIFFTEST_TO_DUT) * ((word_t *) buf + i) = paddr_read(OFFSET(addr, i), WORD_SIZE);
		else paddr_write(OFFSET(addr, i), WORD_SIZE, * ((word_t *) buf + i));
	}
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_DUT) memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
  else memcpy(&cpu, dut, DIFFTEST_REG_SIZE);
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
