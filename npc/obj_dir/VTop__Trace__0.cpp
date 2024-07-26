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
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,((7U & (vlSelf->Top__DOT___inst_memory_inst 
                                      >> 0xcU))),3);
        bufp->chgCData(oldp+1,((vlSelf->Top__DOT___inst_memory_inst 
                                >> 0x19U)),7);
        bufp->chgCData(oldp+2,(vlSelf->Top__DOT____Vcellinp__control_unit__io_op),7);
        bufp->chgCData(oldp+3,(vlSelf->Top__DOT___control_unit_io_control_signals_pc_src),2);
        bufp->chgCData(oldp+4,(((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
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
        bufp->chgBit(oldp+5,(((0xcU != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U))) 
                              & (0x18U != (0x1fU & 
                                           (vlSelf->Top__DOT___inst_memory_inst 
                                            >> 2U))))));
        bufp->chgCData(oldp+6,(((0x1bU == (0x1fU & 
                                           (vlSelf->Top__DOT___inst_memory_inst 
                                            >> 2U)))
                                 ? 3U : ((0x18U == 
                                          (0x1fU & 
                                           (vlSelf->Top__DOT___inst_memory_inst 
                                            >> 2U)))
                                          ? 2U : ((0xcU 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT___inst_memory_inst 
                                                       >> 2U)))
                                                   ? 5U
                                                   : 
                                                  ((8U 
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
        bufp->chgBit(oldp+7,(((0x18U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                  >> 2U))) 
                              & (8U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U))))));
        bufp->chgCData(oldp+8,(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op),3);
        bufp->chgBit(oldp+9,(vlSelf->Top__DOT___control_unit_io_alu_control_signals_unsigned_src));
        bufp->chgBit(oldp+10,(((IData)(((0x30U == (0x7cU 
                                                   & vlSelf->Top__DOT___inst_memory_inst)) 
                                        & ((IData)(
                                                   (0x40000000U 
                                                    == 
                                                    (0x40007000U 
                                                     & vlSelf->Top__DOT___inst_memory_inst))) 
                                           | (1U == 
                                              (3U & 
                                               (vlSelf->Top__DOT___inst_memory_inst 
                                                >> 0xdU)))))) 
                               | ((IData)((0x2010U 
                                           == (0x607cU 
                                               & vlSelf->Top__DOT___inst_memory_inst))) 
                                  | (IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0)))));
        bufp->chgBit(oldp+11,(((0x18U == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                   >> 2U))) 
                               | (IData)((0x2010U == 
                                          (0x601cU 
                                           & vlSelf->Top__DOT___inst_memory_inst))))));
        bufp->chgBit(oldp+12,((IData)((0x1060U == (0x107cU 
                                                   & vlSelf->Top__DOT___inst_memory_inst)))));
        bufp->chgCData(oldp+13,(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op),3);
        bufp->chgBit(oldp+14,(vlSelf->Top__DOT___control_unit_io_mem_control_signals_unsigned_data));
        bufp->chgIData(oldp+15,(vlSelf->Top__DOT___inst_memory_inst),32);
        bufp->chgIData(oldp+16,(vlSelf->Top__DOT___memory_mem_rd_data),32);
        bufp->chgIData(oldp+17,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0),32);
        bufp->chgIData(oldp+18,(vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2),32);
        bufp->chgIData(oldp+19,(vlSelf->Top__DOT__datapath__DOT__pc),32);
        bufp->chgBit(oldp+20,((0U != vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10)));
        bufp->chgIData(oldp+21,(vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1),32);
        bufp->chgIData(oldp+22,(vlSelf->Top__DOT__datapath__DOT____Vcellinp__alu__io_src2),32);
        bufp->chgQData(oldp+23,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1),33);
        bufp->chgQData(oldp+25,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2_),33);
        bufp->chgQData(oldp+27,(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2),33);
        bufp->chgIData(oldp+29,(vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext),32);
        bufp->chgCData(oldp+30,((0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+31,((0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+32,((0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                          >> 7U))),5);
        bufp->chgIData(oldp+33,(vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data),32);
        bufp->chgIData(oldp+34,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_0),32);
        bufp->chgIData(oldp+35,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_1),32);
        bufp->chgIData(oldp+36,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_2),32);
        bufp->chgIData(oldp+37,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_3),32);
        bufp->chgIData(oldp+38,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_4),32);
        bufp->chgIData(oldp+39,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_5),32);
        bufp->chgIData(oldp+40,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_6),32);
        bufp->chgIData(oldp+41,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_7),32);
        bufp->chgIData(oldp+42,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_8),32);
        bufp->chgIData(oldp+43,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_9),32);
        bufp->chgIData(oldp+44,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10),32);
        bufp->chgIData(oldp+45,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_11),32);
        bufp->chgIData(oldp+46,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_12),32);
        bufp->chgIData(oldp+47,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_13),32);
        bufp->chgIData(oldp+48,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_14),32);
        bufp->chgIData(oldp+49,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_15),32);
        bufp->chgIData(oldp+50,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_16),32);
        bufp->chgIData(oldp+51,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_17),32);
        bufp->chgIData(oldp+52,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_18),32);
        bufp->chgIData(oldp+53,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_19),32);
        bufp->chgIData(oldp+54,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_20),32);
        bufp->chgIData(oldp+55,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_21),32);
        bufp->chgIData(oldp+56,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_22),32);
        bufp->chgIData(oldp+57,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_23),32);
        bufp->chgIData(oldp+58,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_24),32);
        bufp->chgIData(oldp+59,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_25),32);
        bufp->chgIData(oldp+60,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_26),32);
        bufp->chgIData(oldp+61,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_27),32);
        bufp->chgIData(oldp+62,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_28),32);
        bufp->chgIData(oldp+63,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_29),32);
        bufp->chgIData(oldp+64,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_30),32);
        bufp->chgIData(oldp+65,(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_31),32);
        bufp->chgCData(oldp+66,(vlSelf->Top__DOT__memory__DOT__mask),4);
        bufp->chgIData(oldp+67,(vlSelf->Top__DOT__memory__DOT__bufs),32);
    }
    bufp->chgBit(oldp+68,(vlSelf->clock));
    bufp->chgBit(oldp+69,(vlSelf->reset));
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
}
