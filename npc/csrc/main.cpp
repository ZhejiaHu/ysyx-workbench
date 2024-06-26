#include <cassert>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <getopt.h>
#include "VTop.h"
#include "VTop__Dpi.h"
#include "svdpi.h"  
#include "verilated.h"
#include "verilated_vcd_c.h"


#define PG_ALIGN __attribute((aligned(4096)))

#define INST_SIZE 4
#define SIM_MBASE 0x80000000
#define SIM_MSIZE 0x8000000
#define DEFAULT_IMG_SIZE 44 


typedef uint32_t paddr_t;
typedef uint32_t word_t; 

static std::string img_path;

static uint8_t* guest_to_host(paddr_t paddr);

static void parse_args(int argc, char** argv) {
    const char* const shortcuts = "i:";
    const option opts[] = {
        {"image_path", required_argument, nullptr, 'i'},
    };
    while (true) {
        const auto opt = getopt_long(argc, argv, shortcuts, opts, nullptr);
        if (opt == -1) break;;
        switch (opt) {
            case 'i':
                img_path = std::string(optarg);
                break;
            default:
                std::cout << "[main.cpp : parse_args] Unknown options is given in command line " << std::string(optarg) << std::endl;
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
    std::streamsize img_size = img_file.tellg();
    assert(img_size < SIM_MSIZE);
    img_file.seekg(0, std::ios::beg);
    std::vector<char> buf(img_size);
    assert(img_file.read(buf.data(), img_size));
    std::copy(buf.begin(), buf.end(), guest_to_host(SIM_MBASE));
    printf("[main.cpp : load_image] Loading image is successful.\n");
}


bool proceed = true;
paddr_t pc = 0x80000000;

// Default image: 
// 00440413: addi	s0,s0,4         |-> x8 = 4
// 27470713: addi	a4,a4,628       |-> x14 = 628
// 00158593: addi	a1,a1,1         |-> x11 = 1
// 1dc68693: addi	a3,a3,476       |-> x13 = 476
// 01868693: addi   a3,a3,24        |-> x13 = 500
// 03268793: addi   a5,a3,50        |-> x15 = 550
// f6a78793: addi   a5,a5,-150      |-> x15 = 400
// ff558593: addi   a1,a1,-11       |-> x11 = -10
// 0c760613: addi   a2,a2,199       |-> x12 = 199
// 2cd60693: addi   a3,a2,717       |-> x13 = 916

static uint8_t pmem[SIM_MSIZE] PG_ALIGN = {
    0x13, 0x04, 0x44, 0x00,     // 0x00440413, 
    0x13, 0x07, 0x47, 0x27,     // 0x27470713,
    0x93, 0x85, 0x15, 0x00,     // 0x00158593,
    0x93, 0x86, 0xc6, 0x1d,     // 0x1dc68693,
    0x93, 0x86, 0x86, 0x01,     // 0x01868693,
    0x93, 0x87, 0x26, 0x03,     // 0x03268793,
    0x93, 0x87, 0xa7, 0xf6,     // 0xf6a78793,
    0x93, 0x85, 0x55, 0xff,     // 0xff558593,
    0x13, 0x06, 0x76, 0x0c,     // 0x0c760613,
    0x93, 0x06, 0xd6, 0x2c,     // 0x2cd60693,
    0x73, 0x00, 0x10, 0x00      // 0x00100073
};


static inline word_t host_read(void* addr, int len) {
    switch (len) {
        case 1: return *(uint8_t *) addr;
        case 2: return *(uint16_t *) addr;
        case 4: return *(uint32_t *) addr;
    }
}


static uint8_t* guest_to_host(paddr_t paddr) {
    return pmem + paddr - SIM_MBASE;
}


static inline bool check_pmem_boundary(uint8_t* host_ptr) {
    return host_ptr >= pmem && host_ptr < pmem + SIM_MSIZE;
}


word_t pmem_read(paddr_t paddr, int len) {
    uint8_t* host_ptr = guest_to_host(paddr);
    if (check_pmem_boundary(host_ptr)) return host_read(host_ptr, len);
    else {
        printf("[pmem.cpp : pmem_read] Invalid host address.\n");
        assert(0);
    }
}


void terminate_simulation() {
    proceed = false;
    printf("[terminate_simulation.c : terminate_simulation] Simulation terminated.\n");
}


int main(int argc, char** argv) {
    parse_args(argc, argv);
    load_image();
    Verilated::mkdir("logs");
    const std::unique_ptr<VerilatedContext> contextp {new VerilatedContext};
    contextp->traceEverOn(true);
    contextp->commandArgs(argc, argv);
    const std::unique_ptr<VTop> vtop {new VTop{contextp.get(), "Top"}};
    VerilatedVcdC* tfp = new VerilatedVcdC;
    vtop->trace(tfp, 99);
    tfp->open("logs/VTop.vcd");    

    // Resetting
    vtop->reset = 1;
    for (int i = 0; i < 10; i++) {
        contextp->timeInc(1);
        vtop->clock = 0;
        vtop->eval();
        vtop->clock = 1;
        vtop->eval();
        tfp->dump(contextp->time());
    }
    vtop->reset = 0;

    // Simulation
    while (!contextp->gotFinish() && proceed) {
        contextp->timeInc(1);
        word_t curr_inst = pmem_read(pc, INST_SIZE);
        vtop->io_inst_valid = 0b1;
        vtop->io_inst_bits = curr_inst;
        vtop->io_pc_ready = 0b1;
        printf("[main.cpp : main] Before evaluation --- current_inst : %x | next_pc : %x \n", curr_inst, vtop->io_pc_bits);
        vtop->clock = 0;
        vtop->eval();
        vtop->clock = 1;
        vtop->eval();
        tfp->dump(contextp->time());
        printf("[main.cpp : main] After evaluation --- pc : %x | io_inst_bits : %x | next_pc : %x\n", pc, vtop->io_inst_bits, vtop->io_pc_bits);
        assert(vtop->io_pc_valid == 0b1);
        assert(vtop->io_pc_bits == pc + 4);
        pc += 4;
    }

    tfp->close();
    printf("[main.cpp : main] Termination has ended.\n");
    return 0;
}
