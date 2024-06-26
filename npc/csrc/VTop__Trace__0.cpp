// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop___024root__trace_chg_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_top_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTop___024root__trace_chg_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<8>/*255:0*/ __Vtemp_hfa4f0165__0;
    VlWide<8>/*255:0*/ __Vtemp_h5eaa95fd__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid));
        bufp->chgCData(oldp+1,(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type),3);
        bufp->chgCData(oldp+2,(vlSelf->Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+3,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_0),32);
        bufp->chgIData(oldp+4,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_1),32);
        bufp->chgIData(oldp+5,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_2),32);
        bufp->chgIData(oldp+6,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_3),32);
        bufp->chgIData(oldp+7,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_4),32);
        bufp->chgIData(oldp+8,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_5),32);
        bufp->chgIData(oldp+9,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_6),32);
        bufp->chgIData(oldp+10,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_7),32);
        bufp->chgIData(oldp+11,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_8),32);
        bufp->chgIData(oldp+12,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_9),32);
        bufp->chgIData(oldp+13,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_10),32);
        bufp->chgIData(oldp+14,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_11),32);
        bufp->chgIData(oldp+15,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_12),32);
        bufp->chgIData(oldp+16,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_13),32);
        bufp->chgIData(oldp+17,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_14),32);
        bufp->chgIData(oldp+18,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_15),32);
        bufp->chgIData(oldp+19,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_16),32);
        bufp->chgIData(oldp+20,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_17),32);
        bufp->chgIData(oldp+21,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_18),32);
        bufp->chgIData(oldp+22,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_19),32);
        bufp->chgIData(oldp+23,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_20),32);
        bufp->chgIData(oldp+24,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_21),32);
        bufp->chgIData(oldp+25,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_22),32);
        bufp->chgIData(oldp+26,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_23),32);
        bufp->chgIData(oldp+27,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_24),32);
        bufp->chgIData(oldp+28,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_25),32);
        bufp->chgIData(oldp+29,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_26),32);
        bufp->chgIData(oldp+30,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_27),32);
        bufp->chgIData(oldp+31,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_28),32);
        bufp->chgIData(oldp+32,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_29),32);
        bufp->chgIData(oldp+33,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_30),32);
        bufp->chgIData(oldp+34,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_31),32);
        bufp->chgIData(oldp+35,(vlSelf->Top__DOT__program_counter__DOT__program_counter),32);
    }
    bufp->chgBit(oldp+36,(vlSelf->clock));
    bufp->chgBit(oldp+37,(vlSelf->reset));
    bufp->chgBit(oldp+38,(vlSelf->io_inst_valid));
    bufp->chgIData(oldp+39,(vlSelf->io_inst_bits),32);
    bufp->chgBit(oldp+40,(vlSelf->io_pc_ready));
    bufp->chgBit(oldp+41,(vlSelf->io_inst_ready));
    bufp->chgBit(oldp+42,(vlSelf->io_pc_valid));
    bufp->chgIData(oldp+43,(vlSelf->io_pc_bits),32);
    bufp->chgCData(oldp+44,((0x7fU & vlSelf->io_inst_bits)),7);
    bufp->chgCData(oldp+45,((7U & (vlSelf->io_inst_bits 
                                   >> 0xcU))),3);
    bufp->chgCData(oldp+46,((0x1fU & (vlSelf->io_inst_bits 
                                      >> 0xfU))),5);
    bufp->chgBit(oldp+47,(((IData)(vlSelf->io_inst_valid) 
                           & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                              | (0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))))));
    bufp->chgCData(oldp+48,((0x1fU & (vlSelf->io_inst_bits 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+49,((0x1fU & (vlSelf->io_inst_bits 
                                      >> 7U))),5);
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
    bufp->chgIData(oldp+50,((((0U == (0x1fU & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                               << 5U)))
                               ? 0U : (__Vtemp_hfa4f0165__0[
                                       (((IData)(0x1fU) 
                                         + (0xffU & 
                                            ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                             << 5U))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                            << 5U))))) 
                             | (__Vtemp_hfa4f0165__0[
                                (7U & (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))] 
                                >> (0x1fU & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                             << 5U))))),32);
    bufp->chgIData(oldp+51,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
                            (0x1fU & (vlSelf->io_inst_bits 
                                      >> 0xfU))]),32);
    bufp->chgBit(oldp+52,((((IData)(vlSelf->io_inst_valid) 
                            | ((IData)(vlSelf->io_inst_valid) 
                               & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                                  | (0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))))) 
                           & (IData)(vlSelf->io_inst_valid))));
    __Vtemp_h5eaa95fd__0[0U] = (IData)((0xffffffffULL 
                                        | ((QData)((IData)(
                                                           (((- (IData)(
                                                                        (vlSelf->io_inst_bits 
                                                                         >> 0x1fU))) 
                                                             << 0xcU) 
                                                            | (vlSelf->io_inst_bits 
                                                               >> 0x14U)))) 
                                           << 0x20U)));
    __Vtemp_h5eaa95fd__0[1U] = (IData)(((0xffffffffULL 
                                         | ((QData)((IData)(
                                                            (((- (IData)(
                                                                         (vlSelf->io_inst_bits 
                                                                          >> 0x1fU))) 
                                                              << 0xcU) 
                                                             | (vlSelf->io_inst_bits 
                                                                >> 0x14U)))) 
                                            << 0x20U)) 
                                        >> 0x20U));
    __Vtemp_h5eaa95fd__0[2U] = (((- (IData)((vlSelf->io_inst_bits 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0xfe0U 
                                              & (vlSelf->io_inst_bits 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlSelf->io_inst_bits 
                                                   >> 7U))));
    __Vtemp_h5eaa95fd__0[3U] = (((- (IData)((vlSelf->io_inst_bits 
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
    __Vtemp_h5eaa95fd__0[4U] = (0xfffff000U & vlSelf->io_inst_bits);
    __Vtemp_h5eaa95fd__0[5U] = (((- (IData)((vlSelf->io_inst_bits 
                                             >> 0x1fU))) 
                                 << 0x14U) | ((0xff000U 
                                               & vlSelf->io_inst_bits) 
                                              | ((0x800U 
                                                  & (vlSelf->io_inst_bits 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->io_inst_bits 
                                                       >> 0x14U)))));
    __Vtemp_h5eaa95fd__0[6U] = 0xffffffffU;
    __Vtemp_h5eaa95fd__0[7U] = 0xffffffffU;
    bufp->chgIData(oldp+53,(((3U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))
                              ? (0x1fU & (vlSelf->io_inst_bits 
                                          >> 0x14U))
                              : (((2U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type)) 
                                  | (1U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type)))
                                  ? (((0U == (0x1fU 
                                              & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                 << 5U)))
                                       ? 0U : (__Vtemp_h5eaa95fd__0[
                                               (((IData)(0x1fU) 
                                                 + 
                                                 (0xffU 
                                                  & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                     << 5U))) 
                                                >> 5U)] 
                                               << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                       << 5U))))) 
                                     | (__Vtemp_h5eaa95fd__0[
                                        (7U & (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))] 
                                        >> (0x1fU & 
                                            ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                             << 5U))))
                                  : ((0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))
                                      ? (0x1fU & (vlSelf->io_inst_bits 
                                                  >> 0x14U))
                                      : 0U)))),32);
    bufp->chgBit(oldp+54,(((IData)(vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid) 
                           & ((IData)(vlSelf->io_inst_valid) 
                              & ((IData)(vlSelf->io_inst_valid) 
                                 | ((IData)(vlSelf->io_inst_valid) 
                                    & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                                       | (0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type)))))))));
    bufp->chgIData(oldp+55,(vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits),32);
    bufp->chgBit(oldp+56,((((IData)(vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid) 
                            & (IData)(vlSelf->io_inst_valid)) 
                           & ((IData)(vlSelf->io_inst_valid) 
                              | ((IData)(vlSelf->io_inst_valid) 
                                 & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                                    | (0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))))))));
}

void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_cleanup\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
