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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        CData/*1:0*/ Top__DOT___control_unit_io_control_signals_pc_src;
        CData/*2:0*/ Top__DOT___control_unit_io_alu_control_signals_alu_op;
        CData/*0:0*/ Top__DOT___control_unit_io_alu_control_signals_unsigned_src;
        CData/*2:0*/ Top__DOT___control_unit_io_mem_control_signals_mem_op;
        CData/*0:0*/ Top__DOT___control_unit_io_mem_control_signals_unsigned_data;
        CData/*6:0*/ Top__DOT____Vcellinp__control_unit__io_op;
        CData/*0:0*/ Top__DOT__datapath__DOT__alu__DOT___GEN;
        CData/*0:0*/ Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0;
        CData/*0:0*/ Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58c07528__0;
        CData/*0:0*/ Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58cc24a5__0;
        CData/*0:0*/ Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h22fcb6cf__0;
        CData/*0:0*/ Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0;
        CData/*0:0*/ Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0;
        CData/*0:0*/ Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0;
        CData/*3:0*/ Top__DOT__memory__DOT__mask;
        CData/*0:0*/ __VdfgTmp_h09a85e04__0;
        CData/*0:0*/ __VdfgTmp_h39c81b96__0;
        CData/*0:0*/ __VdfgTmp_hf2848cc4__0;
        CData/*0:0*/ __Vtrigrprev__TOP__clock;
        CData/*6:0*/ __Vtrigrprev__TOP__Top__DOT____Vcellinp__control_unit__io_op;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ Top__DOT___inst_memory_inst;
        IData/*31:0*/ Top__DOT___memory_mem_rd_data;
        IData/*31:0*/ Top__DOT__datapath__DOT___reg_file_io_rd1;
        IData/*31:0*/ Top__DOT__datapath__DOT___reg_file_io_rd2;
        IData/*31:0*/ Top__DOT__datapath__DOT___extend_io_imm_ext;
        IData/*31:0*/ Top__DOT__datapath__DOT__pc;
        IData/*31:0*/ Top__DOT__datapath__DOT___pc_T;
        IData/*31:0*/ Top__DOT__datapath__DOT____Vcellinp__alu__io_src2;
        IData/*31:0*/ Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        IData/*31:0*/ Top__DOT__datapath__DOT__alu__DOT__io_result_0;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_0;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_1;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_2;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_3;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_4;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_5;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_6;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_7;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_8;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_9;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_10;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_11;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_12;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_13;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_14;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_15;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_16;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_17;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_18;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_19;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_20;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_21;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_22;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_23;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_24;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_25;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_26;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_27;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_28;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_29;
    };
    struct {
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_30;
        IData/*31:0*/ Top__DOT__datapath__DOT__reg_file__DOT__regs_31;
        VlWide<32>/*1023:0*/ Top__DOT__datapath__DOT__reg_file__DOT___GEN;
        IData/*31:0*/ Top__DOT__memory__DOT__bufs;
        IData/*31:0*/ __Vfunc_Top__DOT__memory__DOT__pmem_read__1__Vfuncout;
        IData/*31:0*/ __Vfunc_Top__DOT__inst_memory__DOT__pmem_read__2__Vfuncout;
        IData/*31:0*/ __Vdly__Top__DOT__datapath__DOT__pc;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT__src1;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT__src2_;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT__src2;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT___result_T_6;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT___result_T_7;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT___result_T_9;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT___result_T_11;
        QData/*32:0*/ Top__DOT__datapath__DOT__alu__DOT___result_T_17;
        VlWide<16>/*511:0*/ Top__DOT__datapath__DOT__alu__DOT___GEN_1;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
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
