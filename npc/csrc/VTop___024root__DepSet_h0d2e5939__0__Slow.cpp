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

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    VTop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
    vlSelf->__Vtrigrprev__TOP__Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode 
        = vlSelf->Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode;
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->io_inst_ready = 1U;
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
                VL_FATAL_MT("csrc/../vsrc/Top.sv", 698, "", "Settle region did not converge.");
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

void VTop___024root___ico_sequent__TOP__0__PROF__Top__l61(VTop___024root* vlSelf);
void VTop___024root___nba_sequent__TOP__39__PROF__Top__l62(VTop___024root* vlSelf);
void VTop___024root___ico_sequent__TOP__1__PROF__Top__l693(VTop___024root* vlSelf);
void VTop___024root___ico_sequent__TOP__2__PROF__Top__l125(VTop___024root* vlSelf);
void VTop___024root___ico_sequent__TOP__3__PROF__Top__l124(VTop___024root* vlSelf);
void VTop___024root___nba_sequent__TOP__72__PROF__Top__l191(VTop___024root* vlSelf);
void VTop___024root___ico_sequent__TOP__4__PROF__Top__l634(VTop___024root* vlSelf);
void VTop___024root___ico_sequent__TOP__5__PROF__Top__l173(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VTop___024root___ico_sequent__TOP__0__PROF__Top__l61(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
        VTop___024root___nba_sequent__TOP__39__PROF__Top__l62(vlSelf);
        VTop___024root___ico_sequent__TOP__1__PROF__Top__l693(vlSelf);
        VTop___024root___ico_sequent__TOP__2__PROF__Top__l125(vlSelf);
        VTop___024root___ico_sequent__TOP__3__PROF__Top__l124(vlSelf);
        VTop___024root___nba_sequent__TOP__72__PROF__Top__l191(vlSelf);
        VTop___024root___ico_sequent__TOP__4__PROF__Top__l634(vlSelf);
        VTop___024root___ico_sequent__TOP__5__PROF__Top__l173(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

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
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] Top.execute_unit.__Vcellinp__simulation_termination__opcode)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] Top.execute_unit.__Vcellinp__simulation_termination__opcode)\n");
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
    vlSelf->io_inst_valid = VL_RAND_RESET_I(1);
    vlSelf->io_inst_bits = VL_RAND_RESET_I(32);
    vlSelf->io_pc_ready = VL_RAND_RESET_I(1);
    vlSelf->io_inst_ready = VL_RAND_RESET_I(1);
    vlSelf->io_pc_valid = VL_RAND_RESET_I(1);
    vlSelf->io_pc_bits = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__program_counter__DOT__program_counter = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type = VL_RAND_RESET_I(3);
    vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0 = 0;
    vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode = VL_RAND_RESET_I(7);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_2 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_3 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_4 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_5 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_6 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_7 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_8 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_9 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_10 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_11 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_12 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_13 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_14 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_15 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_16 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_17 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_18 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_19 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_20 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_21 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_22 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_23 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_24 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_25 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_26 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_27 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_28 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_29 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_30 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_31 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(1024, vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN);
    vlSelf->__Vdly__Top__DOT__program_counter__DOT__program_counter = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode = VL_RAND_RESET_I(7);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
