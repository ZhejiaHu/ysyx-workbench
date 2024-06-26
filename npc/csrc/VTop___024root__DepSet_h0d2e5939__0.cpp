// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__0__PROF__Top__l61(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__0__PROF__Top__l61\n"); );
    // Body
    vlSelf->io_pc_valid = vlSelf->io_pc_ready;
}

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__1__PROF__Top__l693(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__1__PROF__Top__l693\n"); );
    // Body
    vlSelf->Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode 
        = ((IData)(vlSelf->io_inst_valid) ? (0x7fU 
                                             & vlSelf->io_inst_bits)
            : 0U);
}

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__2__PROF__Top__l125(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__2__PROF__Top__l125\n"); );
    // Body
    vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0 
        = ((0x13U != (0x7fU & vlSelf->io_inst_bits)) 
           | (0x73U == (0x7fU & vlSelf->io_inst_bits)));
}

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__3__PROF__Top__l124(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__3__PROF__Top__l124\n"); );
    // Body
    vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type 
        = ((0x73U == (0x7fU & vlSelf->io_inst_bits))
            ? 6U : ((0x13U == (0x7fU & vlSelf->io_inst_bits))
                     ? 1U : 7U));
}

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__4__PROF__Top__l634(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__4__PROF__Top__l634\n"); );
    // Body
    vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid 
        = ((~ (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0)) 
           & (IData)(vlSelf->io_inst_valid));
}

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__5__PROF__Top__l173(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__5__PROF__Top__l173\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_hfa4f0165__0;
    // Body
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

void VTop___024root___eval_ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VTop___024root___ico_sequent__TOP__0__PROF__Top__l61(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        VTop___024root___ico_sequent__TOP__1__PROF__Top__l693(vlSelf);
        VTop___024root___ico_sequent__TOP__2__PROF__Top__l125(vlSelf);
        VTop___024root___ico_sequent__TOP__3__PROF__Top__l124(vlSelf);
        VTop___024root___ico_sequent__TOP__4__PROF__Top__l634(vlSelf);
        VTop___024root___ico_sequent__TOP__5__PROF__Top__l173(vlSelf);
    }
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
}

void VTop___024root____Vdpiimwrap_Top__DOT__execute_unit__DOT__simulation_termination__DOT__terminate_simulation_TOP();

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0__PROF__Top__l793(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0__PROF__Top__l793\n"); );
    // Body
    if ((0x73U == (IData)(vlSelf->Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode))) {
        VTop___024root____Vdpiimwrap_Top__DOT__execute_unit__DOT__simulation_termination__DOT__terminate_simulation_TOP();
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__1__PROF__Top__l81(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__1__PROF__Top__l81\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[ProgramCounter.scala] init_pc_str : h80000000 | init_pc : 2147483648 | program_counter : %10# | io.inc.valid : %1# | io.pc_in.valid : 0\n",
                   32,vlSelf->Top__DOT__program_counter__DOT__program_counter,
                   1,(IData)(vlSelf->io_inst_valid));
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__2__PROF__Top__l75(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__2__PROF__Top__l75\n"); );
    // Body
    vlSelf->__Vdly__Top__DOT__program_counter__DOT__program_counter 
        = vlSelf->Top__DOT__program_counter__DOT__program_counter;
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__3__PROF__Top__l454(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__3__PROF__Top__l454\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"Peeking registers value.\n");
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 0] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_0);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 1] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_1);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 2] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_2);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 3] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_3);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 4] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_4);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 5] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_5);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 6] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_6);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 7] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_7);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 8] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_8);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 9] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_9);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 10] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_10);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 11] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_11);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 12] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_12);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 13] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_13);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 14] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_14);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 15] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_15);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 16] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_16);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 17] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_17);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 18] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_18);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 19] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_19);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 20] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_20);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 21] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_21);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 22] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_22);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 23] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_23);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 24] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_24);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 25] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_25);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 26] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_26);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 27] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_27);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 28] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_28);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 29] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_29);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 30] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_30);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Register 31] has value %10#\n",
                   32,vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_31);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"--------------------------------------------------------------------\n");
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__4__PROF__Top__l74(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__4__PROF__Top__l74\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->__Vdly__Top__DOT__program_counter__DOT__program_counter = 0x80000000U;
    } else if (vlSelf->io_inst_valid) {
        vlSelf->__Vdly__Top__DOT__program_counter__DOT__program_counter 
            = ((IData)(4U) + vlSelf->Top__DOT__program_counter__DOT__program_counter);
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__37__PROF__Top__l75(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__37__PROF__Top__l75\n"); );
    // Body
    vlSelf->Top__DOT__program_counter__DOT__program_counter 
        = vlSelf->__Vdly__Top__DOT__program_counter__DOT__program_counter;
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__38__PROF__Top__l258(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__38__PROF__Top__l258\n"); );
    // Init
    CData/*0:0*/ Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1;
    Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1 = 0;
    // Body
    Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1 
        = ((((IData)(vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid) 
             & (IData)(vlSelf->io_inst_valid)) & ((IData)(vlSelf->io_inst_valid) 
                                                  | ((IData)(vlSelf->io_inst_valid) 
                                                     & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                                                        | (0U 
                                                           == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type)))))) 
           & (0U != (0x1fU & (vlSelf->io_inst_bits 
                              >> 7U))));
    if ((0U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_0 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((1U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_1 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((2U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_2 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((3U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_3 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((4U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_4 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((5U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_5 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((6U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_6 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((7U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_7 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((8U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_8 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((9U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_9 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0xaU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_10 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0xbU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_11 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0xcU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_12 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0xdU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_13 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0xeU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_14 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0xfU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_15 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x10U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_16 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x11U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_17 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x12U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_18 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x13U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_19 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x14U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_20 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x15U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_21 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x16U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_22 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x17U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_23 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x18U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_24 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x19U == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_25 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x1aU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_26 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x1bU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_27 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x1cU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_28 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x1dU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_29 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x1eU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_30 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
    if ((0x1fU == (0x1fU & (vlSelf->io_inst_bits >> 7U)))) {
        vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_31 
            = ((IData)(Top__DOT__execute_unit__DOT__register_file__DOT__unnamedblk1__DOT___registers_T_1)
                ? vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits
                : vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
               (0x1fU & (vlSelf->io_inst_bits >> 7U))]);
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__39__PROF__Top__l62(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__39__PROF__Top__l62\n"); );
    // Body
    vlSelf->io_pc_bits = vlSelf->Top__DOT__program_counter__DOT__program_counter;
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__72__PROF__Top__l191(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__72__PROF__Top__l191\n"); );
    // Body
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
}

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VTop___024root___nba_sequent__TOP__0__PROF__Top__l793(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VTop___024root___nba_sequent__TOP__1__PROF__Top__l81(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        VTop___024root___nba_sequent__TOP__2__PROF__Top__l75(vlSelf);
        VTop___024root___nba_sequent__TOP__3__PROF__Top__l454(vlSelf);
        VTop___024root___nba_sequent__TOP__4__PROF__Top__l74(vlSelf);
        VTop___024root___nba_sequent__TOP__37__PROF__Top__l75(vlSelf);
        VTop___024root___nba_sequent__TOP__38__PROF__Top__l258(vlSelf);
        VTop___024root___nba_sequent__TOP__39__PROF__Top__l62(vlSelf);
        VTop___024root___nba_sequent__TOP__72__PROF__Top__l191(vlSelf);
        VTop___024root___ico_sequent__TOP__5__PROF__Top__l173(vlSelf);
    }
}

void VTop___024root___eval_triggers__ico(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf);
#endif  // VL_DEBUG
void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VTop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("csrc/../vsrc/Top.sv", 698, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VTop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VTop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("csrc/../vsrc/Top.sv", 698, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VTop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("csrc/../vsrc/Top.sv", 698, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VTop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_inst_valid & 0xfeU))) {
        Verilated::overWidthError("io_inst_valid");}
    if (VL_UNLIKELY((vlSelf->io_pc_ready & 0xfeU))) {
        Verilated::overWidthError("io_pc_ready");}
}
#endif  // VL_DEBUG
