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

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

typedef int64_t d_sword_t;   // Double signed word
typedef uint64_t d_word_t;   // Double unsigned word 

#ifdef CONFIG_FTRACE
void print_func_trace(vaddr_t cur_pc, vaddr_t jfn_pc, word_t cur_inst);
#endif

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

#define ADD_PC_AND_IMM_TO_DNPC s->dnpc = s->pc + *imm;

static void state_transfer__jal(Decode *s, int rd, word_t *imm) {
  R(rd) = s->pc + 4;
  ADD_PC_AND_IMM_TO_DNPC
  #ifdef CONFIG_FTRACE
  print_func_trace(s->pc, s->dnpc, s->isa.inst.val);
  #endif
}

static void state_transfer__jalr(Decode *s, int rd, word_t *src1, word_t *imm) {
  R(rd) = s->pc + 4;
  s->dnpc = (*src1 + *imm) & ~0b1;
  #ifdef CONFIG_FTRACE
  print_func_trace(s->pc, s->dnpc, s->isa.inst.val);
  #endif
}

static void state_transfer__beq(Decode *s, word_t *src1, word_t *src2, word_t *imm) {
  if (*src1 == *src2) ADD_PC_AND_IMM_TO_DNPC
}

static void state_transfer__bne(Decode *s, word_t *src1, word_t *src2, word_t *imm) {
  if (*src1 != *src2) ADD_PC_AND_IMM_TO_DNPC
}

static void state_transfer__blt(Decode *s, word_t *src1, word_t *src2, word_t *imm) {
  if ((sword_t) *src1 < (sword_t) *src2) ADD_PC_AND_IMM_TO_DNPC
}

static void state_transfer__bltu(Decode *s, word_t *src1, word_t *src2, word_t *imm) {
  if (*src1 < *src2) ADD_PC_AND_IMM_TO_DNPC;
}

static void state_transfer__bge(Decode *s, word_t *src1, word_t *src2, word_t *imm) {
  if ((sword_t) *src1 >= (sword_t) *src2) ADD_PC_AND_IMM_TO_DNPC
}

static void state_transfer__bgeu(Decode *s, word_t *src1, word_t *src2, word_t *imm) {
  if (*src1 >= *src2) ADD_PC_AND_IMM_TO_DNPC
}


#define ST_JAL      state_transfer__jal
#define ST_JALR     state_transfer__jalr
#define ST_BEQ      state_transfer__beq
#define ST_BNE      state_transfer__bne
#define ST_BLT      state_transfer__blt
#define ST_BLTU     state_transfer__bltu
#define ST_BGE      state_transfer__bge
#define ST_BGEU     state_transfer__bgeu

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // none
};

#define src1R()     do { *src1 = R(rs1); } while (0)
#define src2R()     do { *src2 = R(rs2); } while (0)
#define immI()      do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU()      do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS()      do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ()      do { *imm = SEXT(BITS(i, 31, 31) << 20 | BITS(i, 19, 12) << 12 | BITS(i, 20, 20) << 11 | BITS(i, 30, 21) << 1, 21); } while(0)
#define immB()      do { *imm = SEXT(BITS(i, 31, 31) << 12 | BITS(i, 7, 7) << 11 | BITS(i, 30, 25) << 5 | BITS(i, 11, 8) << 1, 13); } while (0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI();      break;
    case TYPE_U:                   immU();      break;
    case TYPE_S: src1R(); src2R(); immS();      break;
    case TYPE_J:                 ; immJ();      break;
    case TYPE_R: src1R(); src2R();              break;
    case TYPE_B: src1R(); src2R(); immB();      break;
  }
}

static int decode_exec(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  // U-type opcode
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  
  // S-type opcode
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));

  // I-type opcode
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = src1 < imm ? 1 : 0);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? ??? ????? 11001 11", jalr   , I, ST_JALR(s, rd, &src1, &imm));
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << (imm & 0b11111));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = src1 >> (imm & 0b11111));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = ((sword_t) src1) >> (imm & 0b11111));
  

  // J-type opcode
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, ST_JAL(s, rd, &imm));

  // R-type opcode
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = (sword_t) src1 - (sword_t) src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << (src2 & 0b11111));
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (((sword_t) src1 < (sword_t) src2) ? 1 : 0));
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = (src1 < src2) ? 1 : 0);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> (src2 & 0b11111));
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = ((sword_t) src1) >> (src2 & 0b11111));
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);

  // R-type opcode (M Extension)
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = (sword_t) src1 * (sword_t) src2);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = (sword_t) (((d_sword_t) (sword_t) src1 * (d_sword_t) (sword_t) src2) >> 32));
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (src2 == 0) ? 0xFFFFFFFF : (sword_t) src1 / (sword_t) src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = (src2 == 0) ? 0xFFFFFFFF : src1 / src2);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (src2 == 0) ? src1 : (sword_t) src1 % (sword_t) src2);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = (src2 == 0) ? src1 : src1 % src2);

  // B-type opcode
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, ST_BEQ(s, &src1, &src2, &imm));
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, ST_BNE(s, &src1, &src2, &imm));
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, ST_BLT(s, &src1, &src2, &imm));
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, ST_BGE(s, &src1, &src2, &imm));
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, ST_BLTU(s, &src1, &src2, &imm));
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, ST_BGEU(s, &src1, &src2, &imm));

  // N-type opcode
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
