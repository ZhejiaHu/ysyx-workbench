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
    tracep->declBit(c+69,"clock", false,-1);
    tracep->declBit(c+70,"reset", false,-1);
    tracep->pushNamePrefix("Top ");
    tracep->declBit(c+69,"clock", false,-1);
    tracep->declBit(c+70,"reset", false,-1);
    tracep->pushNamePrefix("control_unit ");
    tracep->declBus(c+1,"io_funct3", false,-1, 2,0);
    tracep->declBus(c+2,"io_funct7", false,-1, 6,0);
    tracep->declBus(c+3,"io_op", false,-1, 6,0);
    tracep->declBus(c+4,"io_control_signals_pc_src", false,-1, 1,0);
    tracep->declBus(c+5,"io_control_signals_result_src", false,-1, 1,0);
    tracep->declBit(c+6,"io_control_signals_alu_src", false,-1);
    tracep->declBus(c+7,"io_control_signals_imm_src", false,-1, 2,0);
    tracep->declBit(c+8,"io_control_signals_reg_wr", false,-1);
    tracep->declBus(c+9,"io_alu_control_signals_alu_op", false,-1, 2,0);
    tracep->declBit(c+10,"io_alu_control_signals_unsigned_src", false,-1);
    tracep->declBit(c+11,"io_alu_control_signals_negate_src2", false,-1);
    tracep->declBit(c+12,"io_alu_control_signals_compare", false,-1);
    tracep->declBit(c+13,"io_alu_control_signals_compare_flip", false,-1);
    tracep->declBus(c+14,"io_mem_control_signals_mem_op", false,-1, 2,0);
    tracep->declBit(c+15,"io_mem_control_signals_unsigned_data", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("datapath ");
    tracep->declBit(c+69,"clock", false,-1);
    tracep->declBit(c+70,"reset", false,-1);
    tracep->declBus(c+4,"io_control_signals_pc_src", false,-1, 1,0);
    tracep->declBus(c+5,"io_control_signals_result_src", false,-1, 1,0);
    tracep->declBit(c+6,"io_control_signals_alu_src", false,-1);
    tracep->declBus(c+7,"io_control_signals_imm_src", false,-1, 2,0);
    tracep->declBit(c+8,"io_control_signals_reg_wr", false,-1);
    tracep->declBus(c+9,"io_alu_control_signals_alu_op", false,-1, 2,0);
    tracep->declBit(c+10,"io_alu_control_signals_unsigned_src", false,-1);
    tracep->declBit(c+11,"io_alu_control_signals_negate_src2", false,-1);
    tracep->declBit(c+12,"io_alu_control_signals_compare", false,-1);
    tracep->declBit(c+13,"io_alu_control_signals_compare_flip", false,-1);
    tracep->declBus(c+16,"io_instruction", false,-1, 31,0);
    tracep->declBus(c+17,"io_mem_rd_data", false,-1, 31,0);
    tracep->declBus(c+18,"io_mem_addr", false,-1, 31,0);
    tracep->declBus(c+19,"io_mem_wr_data", false,-1, 31,0);
    tracep->declBus(c+20,"io_pc", false,-1, 31,0);
    tracep->declBit(c+21,"io_exit", false,-1);
    tracep->declBus(c+20,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBit(c+69,"clock", false,-1);
    tracep->declBit(c+70,"reset", false,-1);
    tracep->declBus(c+22,"io_src1", false,-1, 31,0);
    tracep->declBus(c+23,"io_src2", false,-1, 31,0);
    tracep->declBus(c+9,"io_alu_control_signals_alu_op", false,-1, 2,0);
    tracep->declBit(c+10,"io_alu_control_signals_unsigned_src", false,-1);
    tracep->declBit(c+11,"io_alu_control_signals_negate_src2", false,-1);
    tracep->declBit(c+12,"io_alu_control_signals_compare", false,-1);
    tracep->declBit(c+13,"io_alu_control_signals_compare_flip", false,-1);
    tracep->declBus(c+18,"io_result", false,-1, 31,0);
    tracep->declBus(c+18,"io_result_0", false,-1, 31,0);
    tracep->declQuad(c+24,"src1", false,-1, 32,0);
    tracep->declQuad(c+26,"src2_", false,-1, 32,0);
    tracep->declQuad(c+28,"src2", false,-1, 32,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("extend ");
    tracep->declBus(c+16,"io_instruction", false,-1, 31,0);
    tracep->declBus(c+7,"io_imm_src", false,-1, 2,0);
    tracep->declBus(c+30,"io_imm_ext", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("reg_file ");
    tracep->declBit(c+69,"clock", false,-1);
    tracep->declBit(c+70,"reset", false,-1);
    tracep->declBus(c+31,"io_rs1", false,-1, 4,0);
    tracep->declBus(c+32,"io_rs2", false,-1, 4,0);
    tracep->declBus(c+33,"io_rd", false,-1, 4,0);
    tracep->declBus(c+34,"io_wr_data", false,-1, 31,0);
    tracep->declBit(c+8,"io_wr_en", false,-1);
    tracep->declBus(c+22,"io_rd1", false,-1, 31,0);
    tracep->declBus(c+19,"io_rd2", false,-1, 31,0);
    tracep->declBit(c+21,"io_exit", false,-1);
    tracep->declBus(c+35,"regs_0", false,-1, 31,0);
    tracep->declBus(c+36,"regs_1", false,-1, 31,0);
    tracep->declBus(c+37,"regs_2", false,-1, 31,0);
    tracep->declBus(c+38,"regs_3", false,-1, 31,0);
    tracep->declBus(c+39,"regs_4", false,-1, 31,0);
    tracep->declBus(c+40,"regs_5", false,-1, 31,0);
    tracep->declBus(c+41,"regs_6", false,-1, 31,0);
    tracep->declBus(c+42,"regs_7", false,-1, 31,0);
    tracep->declBus(c+43,"regs_8", false,-1, 31,0);
    tracep->declBus(c+44,"regs_9", false,-1, 31,0);
    tracep->declBus(c+45,"regs_10", false,-1, 31,0);
    tracep->declBus(c+46,"regs_11", false,-1, 31,0);
    tracep->declBus(c+47,"regs_12", false,-1, 31,0);
    tracep->declBus(c+48,"regs_13", false,-1, 31,0);
    tracep->declBus(c+49,"regs_14", false,-1, 31,0);
    tracep->declBus(c+50,"regs_15", false,-1, 31,0);
    tracep->declBus(c+51,"regs_16", false,-1, 31,0);
    tracep->declBus(c+52,"regs_17", false,-1, 31,0);
    tracep->declBus(c+53,"regs_18", false,-1, 31,0);
    tracep->declBus(c+54,"regs_19", false,-1, 31,0);
    tracep->declBus(c+55,"regs_20", false,-1, 31,0);
    tracep->declBus(c+56,"regs_21", false,-1, 31,0);
    tracep->declBus(c+57,"regs_22", false,-1, 31,0);
    tracep->declBus(c+58,"regs_23", false,-1, 31,0);
    tracep->declBus(c+59,"regs_24", false,-1, 31,0);
    tracep->declBus(c+60,"regs_25", false,-1, 31,0);
    tracep->declBus(c+61,"regs_26", false,-1, 31,0);
    tracep->declBus(c+62,"regs_27", false,-1, 31,0);
    tracep->declBus(c+63,"regs_28", false,-1, 31,0);
    tracep->declBus(c+64,"regs_29", false,-1, 31,0);
    tracep->declBus(c+65,"regs_30", false,-1, 31,0);
    tracep->declBus(c+66,"regs_31", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("inst_memory ");
    tracep->declBus(c+71,"MADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+71,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+20,"pc", false,-1, 31,0);
    tracep->declBus(c+16,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("memory ");
    tracep->declBus(c+71,"MADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+71,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+72,"MEM_CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+73,"MEM_MASK_WIDTH", false,-1, 31,0);
    tracep->declBus(c+14,"mem_control", false,-1, 2,0);
    tracep->declBit(c+15,"mem_unsigned", false,-1);
    tracep->declBus(c+18,"mem_addr", false,-1, 31,0);
    tracep->declBus(c+19,"mem_wr_data", false,-1, 31,0);
    tracep->declBus(c+17,"mem_rd_data", false,-1, 31,0);
    tracep->declBus(c+67,"mask", false,-1, 3,0);
    tracep->declBus(c+68,"bufs", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("terminate ");
    tracep->declBus(c+71,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+74,"OP_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"op", false,-1, 6,0);
    tracep->declBit(c+21,"exit", false,-1);
    tracep->declBus(c+20,"pc", false,-1, 31,0);
    tracep->popNamePrefix(2);
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
    // Body
    bufp->fullCData(oldp+1,((7U & (vlSelf->Top__DOT___inst_memory_inst 
                                   >> 0xcU))),3);
    bufp->fullCData(oldp+2,((vlSelf->Top__DOT___inst_memory_inst 
                             >> 0x19U)),7);
    bufp->fullCData(oldp+3,(vlSelf->Top__DOT____Vcellinp__control_unit__io_op),7);
    bufp->fullCData(oldp+4,(vlSelf->Top__DOT___control_unit_io_control_signals_pc_src),2);
    bufp->fullCData(oldp+5,(((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                              >> 2U)))
                              ? (((0x19U == (0x1fU 
                                             & (vlSelf->Top__DOT___inst_memory_inst 
                                                >> 2U))) 
                                  | (0x1bU == (0x1fU 
                                               & (vlSelf->Top__DOT___inst_memory_inst 
                                                  >> 2U))))
                                  ? 2U : (3U & (- (IData)(
                                                          (5U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->Top__DOT___inst_memory_inst 
                                                               >> 2U)))))))
                              : 1U)),2);
    bufp->fullBit(oldp+6,(((0xcU != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                              >> 2U))) 
                           & (0x18U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U))))));
    bufp->fullCData(oldp+7,(((0x1bU == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U)))
                              ? 3U : ((0x18U == (0x1fU 
                                                 & (vlSelf->Top__DOT___inst_memory_inst 
                                                    >> 2U)))
                                       ? 2U : ((0xcU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT___inst_memory_inst 
                                                    >> 2U)))
                                                ? 5U
                                                : (
                                                   (8U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT___inst_memory_inst 
                                                        >> 2U)))
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlSelf->__VdfgTmp_h09a85e04__0)
                                                     ? 7U
                                                     : 
                                                    ((IData)(vlSelf->__VdfgTmp_h39c81b96__0)
                                                      ? 1U
                                                      : 6U))))))),3);
    bufp->fullBit(oldp+8,(((0x18U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                               >> 2U))) 
                           & (8U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                              >> 2U))))));
    bufp->fullCData(oldp+9,(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op),3);
    bufp->fullBit(oldp+10,(vlSelf->Top__DOT___control_unit_io_alu_control_signals_unsigned_src));
    bufp->fullBit(oldp+11,(((IData)(((0x30U == (0x7cU 
                                                & vlSelf->Top__DOT___inst_memory_inst)) 
                                     & ((IData)((0x40000000U 
                                                 == 
                                                 (0x40007000U 
                                                  & vlSelf->Top__DOT___inst_memory_inst))) 
                                        | (1U == (3U 
                                                  & (vlSelf->Top__DOT___inst_memory_inst 
                                                     >> 0xdU)))))) 
                            | ((IData)((0x2010U == 
                                        (0x607cU & vlSelf->Top__DOT___inst_memory_inst))) 
                               | (IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0)))));
    bufp->fullBit(oldp+12,(((0x18U == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                >> 2U))) 
                            | (IData)((0x2010U == (0x601cU 
                                                   & vlSelf->Top__DOT___inst_memory_inst))))));
    bufp->fullBit(oldp+13,((IData)((0x1060U == (0x107cU 
                                                & vlSelf->Top__DOT___inst_memory_inst)))));
    bufp->fullCData(oldp+14,(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op),3);
    bufp->fullBit(oldp+15,(vlSelf->Top__DOT___control_unit_io_mem_control_signals_unsigned_data));
    bufp->fullIData(oldp+16,(vlSelf->Top__DOT___inst_memory_inst),32);
    bufp->fullIData(oldp+17,(vlSelf->Top__DOT___memory_mem_rd_data),32);
    bufp->fullIData(oldp+18,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0),32);
    bufp->fullIData(oldp+19,(vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2),32);
    bufp->fullIData(oldp+20,(vlSelf->Top__DOT__datapath__DOT__pc),32);
    bufp->fullBit(oldp+21,((0U != vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10)));
    bufp->fullIData(oldp+22,(vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1),32);
    bufp->fullIData(oldp+23,(vlSelf->Top__DOT__datapath__DOT____Vcellinp__alu__io_src2),32);
    bufp->fullQData(oldp+24,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1),33);
    bufp->fullQData(oldp+26,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2_),33);
    bufp->fullQData(oldp+28,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2),33);
    bufp->fullIData(oldp+30,(vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext),32);
    bufp->fullCData(oldp+31,((0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+32,((0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+33,((0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                       >> 7U))),5);
    bufp->fullIData(oldp+34,(vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data),32);
    bufp->fullIData(oldp+35,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_0),32);
    bufp->fullIData(oldp+36,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_1),32);
    bufp->fullIData(oldp+37,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_2),32);
    bufp->fullIData(oldp+38,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_3),32);
    bufp->fullIData(oldp+39,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_4),32);
    bufp->fullIData(oldp+40,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_5),32);
    bufp->fullIData(oldp+41,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_6),32);
    bufp->fullIData(oldp+42,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_7),32);
    bufp->fullIData(oldp+43,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_8),32);
    bufp->fullIData(oldp+44,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_9),32);
    bufp->fullIData(oldp+45,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10),32);
    bufp->fullIData(oldp+46,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_11),32);
    bufp->fullIData(oldp+47,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_12),32);
    bufp->fullIData(oldp+48,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_13),32);
    bufp->fullIData(oldp+49,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_14),32);
    bufp->fullIData(oldp+50,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_15),32);
    bufp->fullIData(oldp+51,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_16),32);
    bufp->fullIData(oldp+52,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_17),32);
    bufp->fullIData(oldp+53,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_18),32);
    bufp->fullIData(oldp+54,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_19),32);
    bufp->fullIData(oldp+55,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_20),32);
    bufp->fullIData(oldp+56,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_21),32);
    bufp->fullIData(oldp+57,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_22),32);
    bufp->fullIData(oldp+58,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_23),32);
    bufp->fullIData(oldp+59,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_24),32);
    bufp->fullIData(oldp+60,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_25),32);
    bufp->fullIData(oldp+61,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_26),32);
    bufp->fullIData(oldp+62,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_27),32);
    bufp->fullIData(oldp+63,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_28),32);
    bufp->fullIData(oldp+64,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_29),32);
    bufp->fullIData(oldp+65,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_30),32);
    bufp->fullIData(oldp+66,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_31),32);
    bufp->fullCData(oldp+67,(vlSelf->Top__DOT__memory__DOT__mask),4);
    bufp->fullIData(oldp+68,(vlSelf->Top__DOT__memory__DOT__bufs),32);
    bufp->fullBit(oldp+69,(vlSelf->clock));
    bufp->fullBit(oldp+70,(vlSelf->reset));
    bufp->fullIData(oldp+71,(0x20U),32);
    bufp->fullIData(oldp+72,(3U),32);
    bufp->fullIData(oldp+73,(4U),32);
    bufp->fullIData(oldp+74,(7U),32);
}
