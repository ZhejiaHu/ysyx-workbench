#ifndef __CPU_RINGBUF_H__
#define __CPU_RINGBUF_H__

#include <common.h>

#define MAX_RINGBUF_SIZE 20

typedef struct {
    vaddr_t pc;
    word_t inst;
} Ringbuf_node;
typedef Ringbuf_node Ringbuf[MAX_RINGBUF_SIZE];


void append_inst_to_ringbuf(vaddr_t pc, word_t inst);
void print_ringbuf();







#endif