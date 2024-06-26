// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


VL_ATTR_COLD void VTop___024root__trace_init_sub__TOP__0(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+37,"clock", false,-1);
    tracep->declBit(c+38,"reset", false,-1);
    tracep->declBit(c+39,"io_inst_valid", false,-1);
    tracep->declBus(c+40,"io_inst_bits", false,-1, 31,0);
    tracep->declBit(c+41,"io_pc_ready", false,-1);
    tracep->declBit(c+42,"io_inst_ready", false,-1);
    tracep->declBit(c+43,"io_pc_valid", false,-1);
    tracep->declBus(c+44,"io_pc_bits", false,-1, 31,0);
    tracep->pushNamePrefix("Top ");
    tracep->declBit(c+37,"clock", false,-1);
    tracep->declBit(c+38,"reset", false,-1);
    tracep->declBit(c+39,"io_inst_valid", false,-1);
    tracep->declBus(c+40,"io_inst_bits", false,-1, 31,0);
    tracep->declBit(c+41,"io_pc_ready", false,-1);
    tracep->declBit(c+42,"io_inst_ready", false,-1);
    tracep->declBit(c+43,"io_pc_valid", false,-1);
    tracep->declBus(c+44,"io_pc_bits", false,-1, 31,0);
    tracep->pushNamePrefix("execute_unit ");
    tracep->declBit(c+37,"clock", false,-1);
    tracep->declBit(c+38,"reset", false,-1);
    tracep->declBit(c+39,"io_opcode_valid", false,-1);
    tracep->declBus(c+45,"io_opcode_bits", false,-1, 6,0);
    tracep->declBus(c+46,"io_funct3_bits", false,-1, 2,0);
    tracep->declBit(c+1,"io_rs1_valid", false,-1);
    tracep->declBus(c+47,"io_rs1_bits", false,-1, 4,0);
    tracep->declBit(c+48,"io_rs2_valid", false,-1);
    tracep->declBus(c+49,"io_rs2_bits", false,-1, 4,0);
    tracep->declBit(c+1,"io_rd_valid", false,-1);
    tracep->declBus(c+50,"io_rd_bits", false,-1, 4,0);
    tracep->declBit(c+39,"io_imm_valid", false,-1);
    tracep->declBus(c+51,"io_imm_bits", false,-1, 31,0);
    tracep->declBit(c+39,"io_inst_type_valid", false,-1);
    tracep->declBus(c+2,"io_inst_type_bits", false,-1, 2,0);
    tracep->declBit(c+39,"io_inc_pc_valid", false,-1);
    tracep->pushNamePrefix("arithmetic_logic_unit ");
    tracep->declBit(c+1,"io_in_operand_1_valid", false,-1);
    tracep->declBus(c+52,"io_in_operand_1_bits", false,-1, 31,0);
    tracep->declBit(c+53,"io_in_operand_2_valid", false,-1);
    tracep->declBus(c+54,"io_in_operand_2_bits", false,-1, 31,0);
    tracep->declBit(c+39,"io_opcode_valid", false,-1);
    tracep->declBus(c+45,"io_opcode_bits", false,-1, 6,0);
    tracep->declBus(c+46,"io_funct3_bits", false,-1, 2,0);
    tracep->declBit(c+55,"io_out_operand_valid", false,-1);
    tracep->declBus(c+56,"io_out_operand_bits", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register_file ");
    tracep->declBit(c+37,"clock", false,-1);
    tracep->declBit(c+38,"reset", false,-1);
    tracep->declBit(c+57,"io_write_bundle_valid", false,-1);
    tracep->declBus(c+50,"io_write_bundle_bits_write_addr", false,-1, 4,0);
    tracep->declBus(c+56,"io_write_bundle_bits_write_data", false,-1, 31,0);
    tracep->declBit(c+1,"io_read_addr_1_valid", false,-1);
    tracep->declBus(c+47,"io_read_addr_1_bits", false,-1, 4,0);
    tracep->declBit(c+1,"io_read_data_1_valid", false,-1);
    tracep->declBus(c+52,"io_read_data_1_bits", false,-1, 31,0);
    tracep->declBus(c+4,"registers_0", false,-1, 31,0);
    tracep->declBus(c+5,"registers_1", false,-1, 31,0);
    tracep->declBus(c+6,"registers_2", false,-1, 31,0);
    tracep->declBus(c+7,"registers_3", false,-1, 31,0);
    tracep->declBus(c+8,"registers_4", false,-1, 31,0);
    tracep->declBus(c+9,"registers_5", false,-1, 31,0);
    tracep->declBus(c+10,"registers_6", false,-1, 31,0);
    tracep->declBus(c+11,"registers_7", false,-1, 31,0);
    tracep->declBus(c+12,"registers_8", false,-1, 31,0);
    tracep->declBus(c+13,"registers_9", false,-1, 31,0);
    tracep->declBus(c+14,"registers_10", false,-1, 31,0);
    tracep->declBus(c+15,"registers_11", false,-1, 31,0);
    tracep->declBus(c+16,"registers_12", false,-1, 31,0);
    tracep->declBus(c+17,"registers_13", false,-1, 31,0);
    tracep->declBus(c+18,"registers_14", false,-1, 31,0);
    tracep->declBus(c+19,"registers_15", false,-1, 31,0);
    tracep->declBus(c+20,"registers_16", false,-1, 31,0);
    tracep->declBus(c+21,"registers_17", false,-1, 31,0);
    tracep->declBus(c+22,"registers_18", false,-1, 31,0);
    tracep->declBus(c+23,"registers_19", false,-1, 31,0);
    tracep->declBus(c+24,"registers_20", false,-1, 31,0);
    tracep->declBus(c+25,"registers_21", false,-1, 31,0);
    tracep->declBus(c+26,"registers_22", false,-1, 31,0);
    tracep->declBus(c+27,"registers_23", false,-1, 31,0);
    tracep->declBus(c+28,"registers_24", false,-1, 31,0);
    tracep->declBus(c+29,"registers_25", false,-1, 31,0);
    tracep->declBus(c+30,"registers_26", false,-1, 31,0);
    tracep->declBus(c+31,"registers_27", false,-1, 31,0);
    tracep->declBus(c+32,"registers_28", false,-1, 31,0);
    tracep->declBus(c+33,"registers_29", false,-1, 31,0);
    tracep->declBus(c+34,"registers_30", false,-1, 31,0);
    tracep->declBus(c+35,"registers_31", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("simulation_termination ");
    tracep->declBus(c+58,"OPCODE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"opcode", false,-1, 6,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("instruction_decode_unit ");
    tracep->declBit(c+39,"io_inst_valid", false,-1);
    tracep->declBus(c+40,"io_inst_bits", false,-1, 31,0);
    tracep->declBit(c+39,"io_opcode_valid", false,-1);
    tracep->declBus(c+45,"io_opcode_bits", false,-1, 6,0);
    tracep->declBus(c+46,"io_funct3_bits", false,-1, 2,0);
    tracep->declBit(c+1,"io_rs1_valid", false,-1);
    tracep->declBus(c+47,"io_rs1_bits", false,-1, 4,0);
    tracep->declBit(c+48,"io_rs2_valid", false,-1);
    tracep->declBus(c+49,"io_rs2_bits", false,-1, 4,0);
    tracep->declBit(c+1,"io_rd_valid", false,-1);
    tracep->declBus(c+50,"io_rd_bits", false,-1, 4,0);
    tracep->declBit(c+39,"io_imm_valid", false,-1);
    tracep->declBus(c+51,"io_imm_bits", false,-1, 31,0);
    tracep->declBit(c+39,"io_inst_type_valid", false,-1);
    tracep->declBus(c+2,"io_inst_type_bits", false,-1, 2,0);
    tracep->declBus(c+2,"inst_type", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("instruction_fetch_unit ");
    tracep->declBit(c+39,"io_inst_in_valid", false,-1);
    tracep->declBus(c+40,"io_inst_in_bits", false,-1, 31,0);
    tracep->declBus(c+44,"io_pc_in_bits", false,-1, 31,0);
    tracep->declBit(c+41,"io_pc_out_ready", false,-1);
    tracep->declBit(c+39,"io_inst_out_valid", false,-1);
    tracep->declBus(c+40,"io_inst_out_bits", false,-1, 31,0);
    tracep->declBit(c+43,"io_pc_out_valid", false,-1);
    tracep->declBus(c+44,"io_pc_out_bits", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("program_counter ");
    tracep->declBit(c+37,"clock", false,-1);
    tracep->declBit(c+38,"reset", false,-1);
    tracep->declBit(c+39,"io_inc_valid", false,-1);
    tracep->declBus(c+44,"io_pc_out_bits", false,-1, 31,0);
    tracep->declBus(c+36,"program_counter", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void VTop___024root__trace_init_top(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_top\n"); );
    // Body
    VTop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTop___024root__trace_register(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTop___024root__trace_full_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_top_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTop___024root__trace_full_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<8>/*255:0*/ __Vtemp_hfa4f0165__0;
    VlWide<8>/*255:0*/ __Vtemp_h5eaa95fd__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid));
    bufp->fullCData(oldp+2,(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type),3);
    bufp->fullCData(oldp+3,(vlSelf->Top__DOT__execute_unit__DOT____Vcellinp__simulation_termination__opcode),7);
    bufp->fullIData(oldp+4,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_0),32);
    bufp->fullIData(oldp+5,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_1),32);
    bufp->fullIData(oldp+6,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_2),32);
    bufp->fullIData(oldp+7,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_3),32);
    bufp->fullIData(oldp+8,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_4),32);
    bufp->fullIData(oldp+9,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_5),32);
    bufp->fullIData(oldp+10,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_6),32);
    bufp->fullIData(oldp+11,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_7),32);
    bufp->fullIData(oldp+12,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_8),32);
    bufp->fullIData(oldp+13,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_9),32);
    bufp->fullIData(oldp+14,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_10),32);
    bufp->fullIData(oldp+15,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_11),32);
    bufp->fullIData(oldp+16,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_12),32);
    bufp->fullIData(oldp+17,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_13),32);
    bufp->fullIData(oldp+18,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_14),32);
    bufp->fullIData(oldp+19,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_15),32);
    bufp->fullIData(oldp+20,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_16),32);
    bufp->fullIData(oldp+21,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_17),32);
    bufp->fullIData(oldp+22,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_18),32);
    bufp->fullIData(oldp+23,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_19),32);
    bufp->fullIData(oldp+24,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_20),32);
    bufp->fullIData(oldp+25,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_21),32);
    bufp->fullIData(oldp+26,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_22),32);
    bufp->fullIData(oldp+27,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_23),32);
    bufp->fullIData(oldp+28,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_24),32);
    bufp->fullIData(oldp+29,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_25),32);
    bufp->fullIData(oldp+30,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_26),32);
    bufp->fullIData(oldp+31,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_27),32);
    bufp->fullIData(oldp+32,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_28),32);
    bufp->fullIData(oldp+33,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_29),32);
    bufp->fullIData(oldp+34,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_30),32);
    bufp->fullIData(oldp+35,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT__registers_31),32);
    bufp->fullIData(oldp+36,(vlSelf->Top__DOT__program_counter__DOT__program_counter),32);
    bufp->fullBit(oldp+37,(vlSelf->clock));
    bufp->fullBit(oldp+38,(vlSelf->reset));
    bufp->fullBit(oldp+39,(vlSelf->io_inst_valid));
    bufp->fullIData(oldp+40,(vlSelf->io_inst_bits),32);
    bufp->fullBit(oldp+41,(vlSelf->io_pc_ready));
    bufp->fullBit(oldp+42,(vlSelf->io_inst_ready));
    bufp->fullBit(oldp+43,(vlSelf->io_pc_valid));
    bufp->fullIData(oldp+44,(vlSelf->io_pc_bits),32);
    bufp->fullCData(oldp+45,((0x7fU & vlSelf->io_inst_bits)),7);
    bufp->fullCData(oldp+46,((7U & (vlSelf->io_inst_bits 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+47,((0x1fU & (vlSelf->io_inst_bits 
                                       >> 0xfU))),5);
    bufp->fullBit(oldp+48,(((IData)(vlSelf->io_inst_valid) 
                            & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                               | (0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))))));
    bufp->fullCData(oldp+49,((0x1fU & (vlSelf->io_inst_bits 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+50,((0x1fU & (vlSelf->io_inst_bits 
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
    bufp->fullIData(oldp+51,((((0U == (0x1fU & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                << 5U)))
                                ? 0U : (__Vtemp_hfa4f0165__0[
                                        (((IData)(0x1fU) 
                                          + (0xffU 
                                             & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
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
    bufp->fullIData(oldp+52,(vlSelf->Top__DOT__execute_unit__DOT__register_file__DOT___GEN[
                             (0x1fU & (vlSelf->io_inst_bits 
                                       >> 0xfU))]),32);
    bufp->fullBit(oldp+53,((((IData)(vlSelf->io_inst_valid) 
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
    bufp->fullIData(oldp+54,(((3U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))
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
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                     << 5U))))) 
                                      | (__Vtemp_h5eaa95fd__0[
                                         (7U & (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))] 
                                         >> (0x1fU 
                                             & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type) 
                                                << 5U))))
                                   : ((0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))
                                       ? (0x1fU & (vlSelf->io_inst_bits 
                                                   >> 0x14U))
                                       : 0U)))),32);
    bufp->fullBit(oldp+55,(((IData)(vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid) 
                            & ((IData)(vlSelf->io_inst_valid) 
                               & ((IData)(vlSelf->io_inst_valid) 
                                  | ((IData)(vlSelf->io_inst_valid) 
                                     & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                                        | (0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type)))))))));
    bufp->fullIData(oldp+56,(vlSelf->Top__DOT__execute_unit__DOT___arithmetic_logic_unit_io_out_operand_bits),32);
    bufp->fullBit(oldp+57,((((IData)(vlSelf->Top__DOT__execute_unit__DOT___register_file_io_read_data_1_valid) 
                             & (IData)(vlSelf->io_inst_valid)) 
                            & ((IData)(vlSelf->io_inst_valid) 
                               | ((IData)(vlSelf->io_inst_valid) 
                                  & ((IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT____VdfgTmp_h56ecf34f__0) 
                                     | (0U == (IData)(vlSelf->Top__DOT__instruction_decode_unit__DOT__inst_type))))))));
    bufp->fullIData(oldp+58,(7U),32);
}
