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
                VL_FATAL_MT("vsrc/Top.sv", 698, "", "Settle region did not converge.");
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

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_hfa4f0165__0;
    // Body
    vlSelf->io_pc_valid = vlSelf->io_pc_ready;
    vlSelf->io_pc_bits = vlSelf->Top__DOT__program_counter__DOT__program_counter;
    vlSelf->Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode 
        = ((IData)(vlSelf->io_inst_valid) ? (0x7fU 
                                             & vlSelf->io_inst_bits)
            : 0U);
    vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0 
        = ((0x13U != (0x7fU & vlSelf->io_inst_bits)) 
           | (0x73U == (0x7fU & vlSelf->io_inst_bits)));
    vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type 
        = ((0x73U == (0x7fU & vlSelf->io_inst_bits))
            ? 6U : ((0x13U == (0x7fU & vlSelf->io_inst_bits))
                     ? 1U : 7U));
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_0;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[1U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_1;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[2U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_2;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[3U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_3;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[4U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_4;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[5U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_5;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[6U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_6;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[7U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_7;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[8U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_8;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[9U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_9;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0xaU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_10;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0xbU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_11;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0xcU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_12;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0xdU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_13;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0xeU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_14;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0xfU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_15;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x10U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_16;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x11U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_17;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x12U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_18;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x13U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_19;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x14U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_20;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x15U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_21;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x16U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_22;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x17U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_23;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x18U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_24;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x19U] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_25;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x1aU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_26;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x1bU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_27;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x1cU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_28;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x1dU] 
        = vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_29;
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x1eU] 
        = (IData)((((QData)((IData)(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_31)) 
                    << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_30))));
    vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[0x1fU] 
        = (IData)(((((QData)((IData)(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_31)) 
                     << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_30))) 
                   >> 0x20U));
    vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid 
        = ((~ (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0)) 
           & (IData)(vlSelf->io_inst_valid));
    __Vtemp_hfa4f0165__0[0U] = (IData)((0xffffffffULL 
                                        | ((QData)((IData)(
                                                           (((- (IData)(
                                                                        (vlSelf->io_inst_bits 
                                                                         >> 0x1fU))) 
                                                             << 0xcU) 
                                                            | (vlSelf->io_inst_bits 
                                                               >> 0x14U)))) 
                                           << 0x20U)));
    __Vtemp_hfa4f0165__0[1U] = (IData)(((0xffffffffULL 
                                         | ((QData)((IData)(
                                                            (((- (IData)(
                                                                         (vlSelf->io_inst_bits 
                                                                          >> 0x1fU))) 
                                                              << 0xcU) 
                                                             | (vlSelf->io_inst_bits 
                                                                >> 0x14U)))) 
                                            << 0x20U)) 
                                        >> 0x20U));
    __Vtemp_hfa4f0165__0[2U] = (((- (IData)((vlSelf->io_inst_bits 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0xfe0U 
                                              & (vlSelf->io_inst_bits 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlSelf->io_inst_bits 
                                                   >> 7U))));
    __Vtemp_hfa4f0165__0[3U] = (((- (IData)((vlSelf->io_inst_bits 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0x800U 
                                              & (vlSelf->io_inst_bits 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSelf->io_inst_bits 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->io_inst_bits 
                                                      >> 7U)))));
    __Vtemp_hfa4f0165__0[4U] = (0xfffff000U & vlSelf->io_inst_bits);
    __Vtemp_hfa4f0165__0[5U] = (((- (IData)((vlSelf->io_inst_bits 
                                             >> 0x1fU))) 
                                 << 0x14U) | ((0xff000U 
                                               & vlSelf->io_inst_bits) 
                                              | ((0x800U 
                                                  & (vlSelf->io_inst_bits 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->io_inst_bits 
                                                       >> 0x14U)))));
    __Vtemp_hfa4f0165__0[6U] = 0xffffffffU;
    __Vtemp_hfa4f0165__0[7U] = 0xffffffffU;
    vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits 
        = ((IData)((0x13U == (0x707fU & vlSelf->io_inst_bits)))
            ? (vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 0xfU))] 
               + ((3U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))
                   ? (0x1fU & (vlSelf->io_inst_bits 
                               >> 0x14U)) : (((2U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type)) 
                                              | (1U 
                                                 == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type)))
                                              ? (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                       << 5U)))
                                                   ? 0U
                                                   : 
                                                  (__Vtemp_hfa4f0165__0[
                                                   (((IData)(0x1fU) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                         << 5U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                        << 5U))))) 
                                                 | (__Vtemp_hfa4f0165__0[
                                                    (7U 
                                                     & (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))] 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                        << 5U))))
                                              : ((0U 
                                                  == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))
                                                  ? 
                                                 (0x1fU 
                                                  & (vlSelf->io_inst_bits 
                                                     >> 0x14U))
                                                  : 0U))))
            : 0U);
}

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
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
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode = VL_RAND_RESET_I(7);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
