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

void VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h800442d7__0;
    // Body
    vlSelf->Top__DOT__datapath__DOT___pc_T = ((IData)(4U) 
                                              + vlSelf->Top__DOT__datapath__DOT__pc);
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_0;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[1U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_1;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[2U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_2;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[3U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_3;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[4U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_4;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[5U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_5;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[6U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_6;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[7U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_7;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[8U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_8;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[9U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_9;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0xaU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0xbU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_11;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0xcU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_12;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0xdU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_13;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0xeU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_14;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0xfU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_15;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x10U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_16;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x11U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_17;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x12U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_18;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x13U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_19;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x14U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_20;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x15U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_21;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x16U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_22;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x17U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_23;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x18U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_24;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x19U] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_25;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x1aU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_26;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x1bU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_27;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x1cU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_28;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x1dU] 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_29;
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x1eU] 
        = (IData)((((QData)((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_31)) 
                    << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_30))));
    vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[0x1fU] 
        = (IData)(((((QData)((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_31)) 
                     << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_30))) 
                   >> 0x20U));
    if ((0U != vlSelf->Top__DOT__datapath__DOT__pc)) {
        VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_read_TOP(vlSelf->Top__DOT__datapath__DOT__pc, vlSelf->__Vfunc_Top__DOT__inst_memory__DOT__pmem_read__2__Vfuncout);
        vlSelf->Top__DOT___inst_memory_inst = vlSelf->__Vfunc_Top__DOT__inst_memory__DOT__pmem_read__2__Vfuncout;
    } else {
        vlSelf->Top__DOT___inst_memory_inst = 0U;
    }
    vlSelf->Top__DOT____Vcellinp__control_unit__io_op 
        = (0x7fU & vlSelf->Top__DOT___inst_memory_inst);
    vlSelf->Top__DOT___control_unit_io_control_signals_pc_src 
        = ((0x1bU == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                               >> 2U))) ? 1U : ((0x18U 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->Top__DOT___inst_memory_inst 
                                                     >> 2U)))
                                                 ? 2U
                                                 : 
                                                (3U 
                                                 & (- (IData)(
                                                              (0x19U 
                                                               == 
                                                               (0x1fU 
                                                                & (vlSelf->Top__DOT___inst_memory_inst 
                                                                   >> 2U))))))));
    vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op 
        = (((~ (IData)((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                        >> 2U))))) 
            & (3U == (3U & vlSelf->Top__DOT___inst_memory_inst)))
            ? (3U & ((IData)(1U) + (vlSelf->Top__DOT___inst_memory_inst 
                                    >> 0xcU))) : ((8U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->Top__DOT___inst_memory_inst 
                                                       >> 2U)))
                                                   ? 
                                                  (4U 
                                                   | (3U 
                                                      & ((IData)(1U) 
                                                         + 
                                                         (vlSelf->Top__DOT___inst_memory_inst 
                                                          >> 0xcU))))
                                                   : 0U));
    vlSelf->Top__DOT___control_unit_io_mem_control_signals_unsigned_data 
        = (1U & ((~ (IData)((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                             >> 2U))))) 
                 & (vlSelf->Top__DOT___inst_memory_inst 
                    >> 0xeU)));
    vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[
        (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                  >> 0x14U))];
    vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[
        (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                  >> 0xfU))];
    vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0 
        = ((4U == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                            >> 2U))) | (0xcU == (0x1fU 
                                                 & (vlSelf->Top__DOT___inst_memory_inst 
                                                    >> 2U))));
    vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0 
        = (IData)((0x4060U == (0x407cU & vlSelf->Top__DOT___inst_memory_inst)));
    vlSelf->__VdfgTmp_h09a85e04__0 = ((0xdU == (0x1fU 
                                                & (vlSelf->Top__DOT___inst_memory_inst 
                                                   >> 2U))) 
                                      | (5U == (0x1fU 
                                                & (vlSelf->Top__DOT___inst_memory_inst 
                                                   >> 2U))));
    vlSelf->__VdfgTmp_h39c81b96__0 = (1U & ((0x19U 
                                             == (0x1fU 
                                                 & (vlSelf->Top__DOT___inst_memory_inst 
                                                    >> 2U))) 
                                            | ((~ (IData)(
                                                          (0U 
                                                           != 
                                                           (0x1fU 
                                                            & (vlSelf->Top__DOT___inst_memory_inst 
                                                               >> 2U))))) 
                                               | (4U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->Top__DOT___inst_memory_inst 
                                                      >> 2U))))));
    vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op 
        = ((1U & (((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0) 
                   & ((~ (vlSelf->Top__DOT___inst_memory_inst 
                          >> 0xeU)) & (IData)((0x1000U 
                                               != (0x3000U 
                                                   & vlSelf->Top__DOT___inst_memory_inst))))) 
                  | ((~ (IData)((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U))))) 
                     | ((8U == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                         >> 2U))) | (IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0)))))
            ? 1U : (((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0) 
                     & (0x1000U == (0x7000U & vlSelf->Top__DOT___inst_memory_inst)))
                     ? 2U : (((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0) 
                              & (0x5000U == (0x7000U 
                                             & vlSelf->Top__DOT___inst_memory_inst)))
                              ? 3U : (((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0) 
                                       & (0x4000U == 
                                          (0x7000U 
                                           & vlSelf->Top__DOT___inst_memory_inst)))
                                       ? 4U : (((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0) 
                                                & (0x6000U 
                                                   == 
                                                   (0x7000U 
                                                    & vlSelf->Top__DOT___inst_memory_inst)))
                                                ? 5U
                                                : (
                                                   ((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0) 
                                                    & (0x7000U 
                                                       == 
                                                       (0x7000U 
                                                        & vlSelf->Top__DOT___inst_memory_inst)))
                                                    ? 6U
                                                    : 
                                                   (7U 
                                                    & (- (IData)((IData)(
                                                                         (0x60U 
                                                                          == 
                                                                          (0x607cU 
                                                                           & vlSelf->Top__DOT___inst_memory_inst))))))))))));
    vlSelf->Top__DOT___control_unit_io_alu_control_signals_unsigned_src 
        = (((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_h19288ea6__0) 
            & ((3U == (7U & (vlSelf->Top__DOT___inst_memory_inst 
                             >> 0xcU))) | (IData)((0x5000U 
                                                   == 
                                                   (0xfe007000U 
                                                    & vlSelf->Top__DOT___inst_memory_inst))))) 
           | ((IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0) 
              & (vlSelf->Top__DOT___inst_memory_inst 
                 >> 0xdU)));
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58cc24a5__0 
        = ((0x1bU == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                               >> 2U))) | ((0x18U != 
                                            (0x1fU 
                                             & (vlSelf->Top__DOT___inst_memory_inst 
                                                >> 2U))) 
                                           & ((0xcU 
                                               == (0x1fU 
                                                   & (vlSelf->Top__DOT___inst_memory_inst 
                                                      >> 2U))) 
                                              | ((8U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->Top__DOT___inst_memory_inst 
                                                      >> 2U))) 
                                                 & ((IData)(vlSelf->__VdfgTmp_h09a85e04__0) 
                                                    | (IData)(vlSelf->__VdfgTmp_h39c81b96__0))))));
    vlSelf->__VdfgTmp_hf2848cc4__0 = ((8U != (0x1fU 
                                              & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U))) 
                                      & ((~ (IData)(vlSelf->__VdfgTmp_h39c81b96__0)) 
                                         | (IData)(vlSelf->__VdfgTmp_h09a85e04__0)));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN 
        = ((~ (IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_unsigned_src)) 
           & (vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1 
              >> 0x1fU));
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h22fcb6cf__0 
        = (1U & ((IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58cc24a5__0)
                  ? (vlSelf->Top__DOT___inst_memory_inst 
                     >> 0x14U) : (vlSelf->Top__DOT___inst_memory_inst 
                                  >> 7U)));
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0 
        = ((0x1bU != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                               >> 2U))) & ((0x18U != 
                                            (0x1fU 
                                             & (vlSelf->Top__DOT___inst_memory_inst 
                                                >> 2U))) 
                                           & ((0xcU 
                                               == (0x1fU 
                                                   & (vlSelf->Top__DOT___inst_memory_inst 
                                                      >> 2U))) 
                                              | (IData)(vlSelf->__VdfgTmp_hf2848cc4__0))));
    vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58c07528__0 
        = ((0x1bU == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                               >> 2U))) | ((0x18U == 
                                            (0x1fU 
                                             & (vlSelf->Top__DOT___inst_memory_inst 
                                                >> 2U))) 
                                           | ((0xcU 
                                               != (0x1fU 
                                                   & (vlSelf->Top__DOT___inst_memory_inst 
                                                      >> 2U))) 
                                              & (IData)(vlSelf->__VdfgTmp_hf2848cc4__0))));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 
        = (((QData)((IData)(vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN)) 
            << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1)));
    vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext 
        = ((0x80000000U & vlSelf->Top__DOT___inst_memory_inst) 
           | ((0x7ff00000U & (((IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0)
                                ? (vlSelf->Top__DOT___inst_memory_inst 
                                   >> 0x14U) : (- (IData)(
                                                          (vlSelf->Top__DOT___inst_memory_inst 
                                                           >> 0x1fU)))) 
                              << 0x14U)) | ((0xff000U 
                                             & ((((IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58c07528__0) 
                                                  & (IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58cc24a5__0))
                                                  ? 
                                                 (vlSelf->Top__DOT___inst_memory_inst 
                                                  >> 0xcU)
                                                  : 
                                                 (- (IData)(
                                                            (vlSelf->Top__DOT___inst_memory_inst 
                                                             >> 0x1fU)))) 
                                                << 0xcU)) 
                                            | ((0x800U 
                                                & ((((IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0) 
                                                     ^ (IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58c07528__0))
                                                     ? (IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h22fcb6cf__0)
                                                     : 
                                                    ((~ (IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0)) 
                                                     & (vlSelf->Top__DOT___inst_memory_inst 
                                                        >> 0x1fU))) 
                                                   << 0xbU)) 
                                               | ((((IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0)
                                                     ? 0U
                                                     : 
                                                    (0x3fU 
                                                     & (vlSelf->Top__DOT___inst_memory_inst 
                                                        >> 0x19U))) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h5883041f__0)
                                                        ? 0U
                                                        : 
                                                       (0xfU 
                                                        & ((IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58cc24a5__0)
                                                            ? 
                                                           (vlSelf->Top__DOT___inst_memory_inst 
                                                            >> 0x15U)
                                                            : 
                                                           (vlSelf->Top__DOT___inst_memory_inst 
                                                            >> 8U)))) 
                                                      << 1U) 
                                                     | ((~ (IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h58c07528__0)) 
                                                        & (IData)(vlSelf->Top__DOT__datapath__DOT__extend__DOT____VdfgTmp_h22fcb6cf__0))))))));
    vlSelf->Top__DOT__datapath__DOT____Vcellinp__alu__io_src2 
        = (((0xcU != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                               >> 2U))) & (0x18U != 
                                           (0x1fU & 
                                            (vlSelf->Top__DOT___inst_memory_inst 
                                             >> 2U))))
            ? vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext
            : vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2_ 
        = (((QData)((IData)(((~ (IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_unsigned_src)) 
                             & (vlSelf->Top__DOT__datapath__DOT____Vcellinp__alu__io_src2 
                                >> 0x1fU)))) << 0x20U) 
           | (QData)((IData)(vlSelf->Top__DOT__datapath__DOT____Vcellinp__alu__io_src2)));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2 
        = (0x1ffffffffULL & (((IData)(((0x30U == (0x7cU 
                                                  & vlSelf->Top__DOT___inst_memory_inst)) 
                                       & ((IData)((0x40000000U 
                                                   == 
                                                   (0x40007000U 
                                                    & vlSelf->Top__DOT___inst_memory_inst))) 
                                          | (1U == 
                                             (3U & 
                                              (vlSelf->Top__DOT___inst_memory_inst 
                                               >> 0xdU)))))) 
                              | ((IData)((0x2010U == 
                                          (0x607cU 
                                           & vlSelf->Top__DOT___inst_memory_inst))) 
                                 | (IData)(vlSelf->Top__DOT__control_unit__DOT____VdfgTmp_hfa2f1baf__0)))
                              ? (1ULL + (~ vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2_))
                              : vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2_));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_6 
        = (0x1ffffffffULL & VL_SHIFTRS_QQI(33,33,5, vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1, 
                                           (0x1fU & (IData)(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2))));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_7 
        = (vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 
           ^ vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_9 
        = (vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 
           | vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_11 
        = (vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 
           & vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2);
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17 
        = (0x1ffffffffULL & ((1U == (IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op))
                              ? (vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 
                                 + vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2)
                              : vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[0U] 
        = (IData)((((QData)((IData)((0x7fffffffU & 
                                     (- (IData)((1U 
                                                 & (IData)(
                                                           (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17 
                                                            >> 0x20U)))))))) 
                    << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[1U] 
        = (IData)(((((QData)((IData)((0x7fffffffU & 
                                      (- (IData)((1U 
                                                  & (IData)(
                                                            (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17 
                                                             >> 0x20U)))))))) 
                     << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[2U] 
        = (IData)((((QData)((IData)((0x7fffffffU & 
                                     (- (IData)((1U 
                                                 & (IData)(
                                                           (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17 
                                                            >> 0x20U)))))))) 
                    << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[3U] 
        = (IData)(((((QData)((IData)((0x7fffffffU & 
                                      (- (IData)((1U 
                                                  & (IData)(
                                                            (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17 
                                                             >> 0x20U)))))))) 
                     << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_17) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[4U] 
        = (IData)(((((QData)((IData)((- (IData)((IData)(vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN))))) 
                     << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1))) 
                   << (0x1fU & (IData)(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2))));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[5U] 
        = (IData)((((((QData)((IData)((- (IData)((IData)(vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN))))) 
                      << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1))) 
                    << (0x1fU & (IData)(vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2))) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[6U] 
        = (IData)((((QData)((IData)((0x7fffffffU & 
                                     (- (IData)((1U 
                                                 & (IData)(
                                                           (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_6 
                                                            >> 0x20U)))))))) 
                    << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_6));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[7U] 
        = (IData)(((((QData)((IData)((0x7fffffffU & 
                                      (- (IData)((1U 
                                                  & (IData)(
                                                            (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_6 
                                                             >> 0x20U)))))))) 
                     << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_6) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[8U] 
        = (IData)((((QData)((IData)((0x7fffffffU & 
                                     (- (IData)((1U 
                                                 & (IData)(
                                                           (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_7 
                                                            >> 0x20U)))))))) 
                    << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_7));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[9U] 
        = (IData)(((((QData)((IData)((0x7fffffffU & 
                                      (- (IData)((1U 
                                                  & (IData)(
                                                            (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_7 
                                                             >> 0x20U)))))))) 
                     << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_7) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[0xaU] 
        = (IData)((((QData)((IData)((0x7fffffffU & 
                                     (- (IData)((1U 
                                                 & (IData)(
                                                           (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_9 
                                                            >> 0x20U)))))))) 
                    << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_9));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[0xbU] 
        = (IData)(((((QData)((IData)((0x7fffffffU & 
                                      (- (IData)((1U 
                                                  & (IData)(
                                                            (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_9 
                                                             >> 0x20U)))))))) 
                     << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_9) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[0xcU] 
        = (IData)((((QData)((IData)((0x7fffffffU & 
                                     (- (IData)((1U 
                                                 & (IData)(
                                                           (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_11 
                                                            >> 0x20U)))))))) 
                    << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_11));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[0xdU] 
        = (IData)(((((QData)((IData)((0x7fffffffU & 
                                      (- (IData)((1U 
                                                  & (IData)(
                                                            (vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_11 
                                                             >> 0x20U)))))))) 
                     << 0x21U) | vlSelf->Top__DOT__datapath__DOT__alu__DOT___result_T_11) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[0xeU] 
        = (IData)((- (QData)((IData)((vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 
                                      == vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2)))));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[0xfU] 
        = (IData)(((- (QData)((IData)((vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1 
                                       == vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2)))) 
                   >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0 
        = (((0x18U == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                >> 2U))) | (IData)(
                                                   (0x2010U 
                                                    == 
                                                    (0x601cU 
                                                     & vlSelf->Top__DOT___inst_memory_inst))))
            ? (1U & ((IData)((0x1060U == (0x107cU & vlSelf->Top__DOT___inst_memory_inst))) 
                     ^ (vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[
                        (0xfU & (((IData)(0x20U) + 
                                  ((IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op) 
                                   << 6U)) >> 5U))] 
                        >> (0x1fU & ((IData)(0x20U) 
                                     + ((IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op) 
                                        << 6U))))))
            : (((0U == (0x1fU & ((IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op) 
                                 << 6U))) ? 0U : (vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[
                                                  (((IData)(0x1fU) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op) 
                                                        << 6U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op) 
                                                       << 6U))))) 
               | (vlSelf->Top__DOT__datapath__DOT__alu__DOT___GEN_1[
                  (0xeU & ((IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op) 
                           << 1U))] >> (0x1fU & ((IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op) 
                                                 << 6U)))));
    vlSelf->Top__DOT__memory__DOT__mask = (((((3U == 
                                               (3U 
                                                & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0)) 
                                              | ((2U 
                                                  == 
                                                  (3U 
                                                   & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0)) 
                                                 & (2U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op))))) 
                                             | (3U 
                                                == 
                                                (3U 
                                                 & (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op)))) 
                                            << 3U) 
                                           | ((((2U 
                                                 == 
                                                 (3U 
                                                  & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0)) 
                                                | (3U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op)))) 
                                               << 2U) 
                                              | ((((1U 
                                                    == 
                                                    (3U 
                                                     & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0)) 
                                                   << 1U) 
                                                  | (0xfffffffeU 
                                                     & (((0U 
                                                          == 
                                                          (3U 
                                                           & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0)) 
                                                         << 1U) 
                                                        & (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op)))) 
                                                 | (0U 
                                                    == 
                                                    (3U 
                                                     & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0)))));
    if ((IData)((((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op) 
                  >> 2U) & (((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op) 
                             >> 1U) | (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op))))) {
        VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_write_TOP(vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0, vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2, (IData)(vlSelf->Top__DOT__memory__DOT__mask));
        vlSelf->Top__DOT___memory_mem_rd_data = 0U;
    } else if ((1U & ((~ ((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op) 
                          >> 2U)) & (((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op) 
                                      >> 1U) | (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op))))) {
        VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_read_TOP(vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0, vlSelf->__Vfunc_Top__DOT__memory__DOT__pmem_read__1__Vfuncout);
        vlSelf->Top__DOT__memory__DOT__bufs = (vlSelf->__Vfunc_Top__DOT__memory__DOT__pmem_read__1__Vfuncout 
                                               & (((- (IData)(
                                                              (1U 
                                                               & ((IData)(vlSelf->Top__DOT__memory__DOT__mask) 
                                                                  >> 3U)))) 
                                                   << 0x18U) 
                                                  | ((0xff0000U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & ((IData)(vlSelf->Top__DOT__memory__DOT__mask) 
                                                                        >> 2U)))) 
                                                         << 0x10U)) 
                                                     | ((0xff00U 
                                                         & ((- (IData)(
                                                                       (1U 
                                                                        & ((IData)(vlSelf->Top__DOT__memory__DOT__mask) 
                                                                           >> 1U)))) 
                                                            << 8U)) 
                                                        | (0xffU 
                                                           & (- (IData)(
                                                                        (1U 
                                                                         & (IData)(vlSelf->Top__DOT__memory__DOT__mask)))))))));
        if ((1U == (3U & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0))) {
            vlSelf->Top__DOT__memory__DOT__bufs = (vlSelf->Top__DOT__memory__DOT__bufs 
                                                   >> 8U);
        } else if ((2U == (3U & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0))) {
            vlSelf->Top__DOT__memory__DOT__bufs = (vlSelf->Top__DOT__memory__DOT__bufs 
                                                   >> 0x10U);
        } else if ((3U == (3U & vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0))) {
            vlSelf->Top__DOT__memory__DOT__bufs = (vlSelf->Top__DOT__memory__DOT__bufs 
                                                   >> 0x18U);
        }
        vlSelf->Top__DOT___memory_mem_rd_data = ((1U 
                                                  == 
                                                  (3U 
                                                   & (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op)))
                                                  ? 
                                                 ((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_unsigned_data)
                                                   ? 
                                                  (0xffU 
                                                   & vlSelf->Top__DOT__memory__DOT__bufs)
                                                   : 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->Top__DOT__memory__DOT__bufs 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & vlSelf->Top__DOT__memory__DOT__bufs)))
                                                  : 
                                                 ((2U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op)))
                                                   ? 
                                                  ((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_unsigned_data)
                                                    ? 
                                                   (0xffffU 
                                                    & vlSelf->Top__DOT__memory__DOT__bufs)
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->Top__DOT__memory__DOT__bufs 
                                                                    >> 0xfU)))) 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & vlSelf->Top__DOT__memory__DOT__bufs)))
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op)))
                                                    ? vlSelf->Top__DOT__memory__DOT__bufs
                                                    : 0U)));
    } else {
        vlSelf->Top__DOT___memory_mem_rd_data = 0U;
    }
    __Vtemp_h800442d7__0[0U] = vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0;
    __Vtemp_h800442d7__0[1U] = vlSelf->Top__DOT___memory_mem_rd_data;
    __Vtemp_h800442d7__0[2U] = (IData)((((QData)((IData)(
                                                         (vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext 
                                                          + vlSelf->Top__DOT__datapath__DOT__pc))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((IData)(4U) 
                                                           + vlSelf->Top__DOT__datapath__DOT__pc)))));
    __Vtemp_h800442d7__0[3U] = (IData)(((((QData)((IData)(
                                                          (vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext 
                                                           + vlSelf->Top__DOT__datapath__DOT__pc))) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           ((IData)(4U) 
                                                            + vlSelf->Top__DOT__datapath__DOT__pc)))) 
                                        >> 0x20U));
    vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data 
        = (((0U == (0x1fU & (((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
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
                               : 1U) << 5U))) ? 0U : 
            (__Vtemp_h800442d7__0[(((IData)(0x1fU) 
                                    + (0x7fU & (((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->Top__DOT___inst_memory_inst 
                                                      >> 2U)))
                                                  ? 
                                                 (((0x19U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->Top__DOT___inst_memory_inst 
                                                        >> 2U))) 
                                                   | (0x1bU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->Top__DOT___inst_memory_inst 
                                                          >> 2U))))
                                                   ? 2U
                                                   : 
                                                  (3U 
                                                   & (- (IData)(
                                                                (5U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (vlSelf->Top__DOT___inst_memory_inst 
                                                                     >> 2U)))))))
                                                  : 1U) 
                                                << 5U))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & (((0U 
                                                       != 
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT___inst_memory_inst 
                                                           >> 2U)))
                                                       ? 
                                                      (((0x19U 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT___inst_memory_inst 
                                                             >> 2U))) 
                                                        | (0x1bU 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->Top__DOT___inst_memory_inst 
                                                               >> 2U))))
                                                        ? 2U
                                                        : 
                                                       (3U 
                                                        & (- (IData)(
                                                                     (5U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (vlSelf->Top__DOT___inst_memory_inst 
                                                                          >> 2U)))))))
                                                       : 1U) 
                                                     << 5U))))) 
           | (__Vtemp_h800442d7__0[((0U != (0x1fU & 
                                            (vlSelf->Top__DOT___inst_memory_inst 
                                             >> 2U)))
                                     ? (((0x19U == 
                                          (0x1fU & 
                                           (vlSelf->Top__DOT___inst_memory_inst 
                                            >> 2U))) 
                                         | (0x1bU == 
                                            (0x1fU 
                                             & (vlSelf->Top__DOT___inst_memory_inst 
                                                >> 2U))))
                                         ? 2U : (3U 
                                                 & (- (IData)(
                                                              (5U 
                                                               == 
                                                               (0x1fU 
                                                                & (vlSelf->Top__DOT___inst_memory_inst 
                                                                   >> 2U)))))))
                                     : 1U)] >> (0x1fU 
                                                & (((0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlSelf->Top__DOT___inst_memory_inst 
                                                         >> 2U)))
                                                     ? 
                                                    (((0x19U 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->Top__DOT___inst_memory_inst 
                                                           >> 2U))) 
                                                      | (0x1bU 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->Top__DOT___inst_memory_inst 
                                                             >> 2U))))
                                                      ? 2U
                                                      : 
                                                     (3U 
                                                      & (- (IData)(
                                                                   (5U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (vlSelf->Top__DOT___inst_memory_inst 
                                                                        >> 2U)))))))
                                                     : 1U) 
                                                   << 5U))));
}

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
