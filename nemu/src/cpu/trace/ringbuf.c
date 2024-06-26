#include <cpu/ringbuf.h>

Ringbuf ringbuf;
int cur_node = 0;

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);


void append_inst_to_ringbuf(vaddr_t cur_pc, word_t cur_inst) {
    ringbuf[cur_node].pc = cur_pc;
    ringbuf[cur_node].inst = cur_inst;
    cur_node = (cur_node + 1) % MAX_RINGBUF_SIZE;
}


void print_ringbuf() {
    int i = 0;
    int start = ringbuf[cur_node].pc == 0 ? 0: cur_node;
    Log("Ringbuf information --- start : %d : cur_node : %d.", start, cur_node);
    while (i != MAX_RINGBUF_SIZE) {
        char buf[128];
        char* p = buf;
        int cur_idx = (start + i) % MAX_RINGBUF_SIZE;
        p += snprintf(p, 16, "  %s  ", i == MAX_RINGBUF_SIZE - 1 ? "--->" : "    ");

        vaddr_t cur_pc = ringbuf[cur_idx].pc;
        word_t cur_inst = ringbuf[cur_idx].inst;
        if (cur_pc == 0) break;
        p += snprintf(p, sizeof(buf), FMT_WORD ":", cur_pc);

        uint8_t *inst_dp = (uint8_t *) &cur_inst;
        for (int i = MUXDEF(CONFIG_ISA_x86, 8, 4) - 1; i + 1; i--) p += snprintf(p, 4, " %02x", inst_dp[i]);
        p += snprintf(p, 8, "    ");
        disassemble(p, buf + sizeof(buf) - p, cur_pc, inst_dp, 4);
        Log("(Ringbuf result) : %s", buf);
        i++;
    }
}