// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
    vlSelf->__Vtrigrprev__TOP__Top__DOT____Vcellinp__control_unit__io_op 
        = vlSelf->Top__DOT____Vcellinp__control_unit__io_op;
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VTop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/Top.sv", 467, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VTop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] Top.__Vcellinp__control_unit__io_op)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] Top.__Vcellinp__control_unit__io_op)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT___inst_memory_inst = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT___memory_mem_rd_data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT___control_unit_io_control_signals_pc_src = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT___control_unit_io_alu_control_signals_unsigned_src = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT___control_unit_io_mem_control_signals_unsigned_data = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT____Vcellinp__control_unit__io_op = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT___pc_T = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT____Vcellinp__alu__io_src2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2_ = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2 = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_6 = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_7 = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_9 = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_11 = VL_RAND_RESET_Q(33);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17 = VL_RAND_RESET_Q(33);
    VL_RAND_RESET_W(512, vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1);
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0 = 0;
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58c07528__0 = 0;
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58cc24a5__0 = 0;
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h22fcb6cf__0 = 0;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_3 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_4 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_5 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_6 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_7 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_8 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_9 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_11 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_12 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_13 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_14 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_15 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_16 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_17 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_18 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_19 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_20 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_21 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_22 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_23 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_24 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_25 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_26 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_27 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_28 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_29 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_30 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_31 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(1024, vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0 = 0;
    vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0 = 0;
    vlSelf->Top__DOT__memory__DOT__mask = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__memory__DOT__bufs = VL_RAND_RESET_I(32);
    vlSelf->__VdfgTmp_h09a85e04__0 = 0;
    vlSelf->__VdfgTmp_h39c81b96__0 = 0;
    vlSelf->__VdfgTmp_hf2848cc4__0 = 0;
    vlSelf->__Vfunc_Top__DOT__memory__DOT__pmem_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_Top__DOT__inst_memory__DOT__pmem_read__2__Vfuncout = 0;
    vlSelf->__Vdly__Top__DOT__datapath__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__Top__DOT____Vcellinp__control_unit__io_op = VL_RAND_RESET_I(7);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
