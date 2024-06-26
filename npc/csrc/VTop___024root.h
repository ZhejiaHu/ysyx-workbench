// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class VTop__Syms;

class VTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_inst_valid,0,0);
    VL_IN8(io_pc_ready,0,0);
    VL_OUT8(io_inst_ready,0,0);
    VL_OUT8(io_pc_valid,0,0);
    CData/*2:0*/ Top__DOT__instruction_decode_unit__DOT__inst_type;
    CData/*0:0*/ Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0;
    CData/*0:0*/ Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid;
    CData/*6:0*/ Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode;
    CData/*0:0*/ __Vtrigrprev__TOP__clock;
    CData/*6:0*/ __Vtrigrprev__TOP__Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    VL_IN(io_inst_bits,31,0);
    VL_OUT(io_pc_bits,31,0);
    IData/*31:0*/ Top__DOT__program_counter__DOT__program_counter;
    IData/*31:0*/ Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_0;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_1;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_2;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_3;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_4;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_5;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_6;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_7;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_8;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_9;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_10;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_11;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_12;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_13;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_14;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_15;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_16;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_17;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_18;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_19;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_20;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_21;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_22;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_23;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_24;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_25;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_26;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_27;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_28;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_29;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_30;
    IData/*31:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__registers_31;
    VlWide<32>/*1023:0*/ Top__DOT__execute_unit__DOT__register_file__DOT___GEN;
    IData/*31:0*/ __Vdly__Top__DOT__program_counter__DOT__program_counter;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
