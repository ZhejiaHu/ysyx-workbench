// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop___024root.h"

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Datapath] alu.io.result --- 0x%x | reg_file.io.rd --- %2# | reg_file.io.wr_en --- %1# | io.control_signals.result_src --- %1# | io.control_signals.pc_src --- %1# | alu.io.result --- %1# \n",
                   32,vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0,
                   5,(0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                               >> 7U)),1,((0x18U != 
                                           (0x1fU & 
                                            (vlSelf->Top__DOT___inst_memory_inst 
                                             >> 2U))) 
                                          & (8U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U)))),
                   2,((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                       >> 2U))) ? (
                                                   ((0x19U 
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
                       : 1U),2,(IData)(vlSelf->Top__DOT___control_unit_io_control_signals_pc_src),
                   1,(1U == vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[ALU] src1 --- 0x%x | src2 --- 0x%x | io.alu_control_signals.alu_op --- 0x%x | io.alu_control_signals.compare --- 0x%x | io.alu_control_signals.compare_flip --- 0x%x | io.result --- 0x%x\n",
                   33,vlSelf->Top__DOT__datapath__DOT__alu__DOT__src1,
                   33,vlSelf->Top__DOT__datapath__DOT__alu__DOT__src2,
                   3,(IData)(vlSelf->Top__DOT___control_unit_io_alu_control_signals_alu_op),
                   1,((0x18U == (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                          >> 2U))) 
                      | (IData)((0x2010U == (0x601cU 
                                             & vlSelf->Top__DOT___inst_memory_inst)))),
                   1,(IData)((0x1060U == (0x107cU & vlSelf->Top__DOT___inst_memory_inst))),
                   32,vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[Top] io.instruction = 0x%x | io.pc = 0x%x\n",
                   32,vlSelf->Top__DOT___inst_memory_inst,
                   32,vlSelf->Top__DOT__datapath__DOT__pc);
    }
    vlSelf->__Vdly__Top__DOT__datapath__DOT__pc = vlSelf->Top__DOT__datapath__DOT__pc;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->reset))))) {
        VL_FWRITEF(0x80000002U,"[RegisterFile] io.rd : %2# | io.wr_en : %1# | io.wr_data : %10#\n[RegisterFile] Register 10 (a0): 0x%x\n",
                   5,(0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                               >> 7U)),1,((0x18U != 
                                           (0x1fU & 
                                            (vlSelf->Top__DOT___inst_memory_inst 
                                             >> 2U))) 
                                          & (8U != 
                                             (0x1fU 
                                              & (vlSelf->Top__DOT___inst_memory_inst 
                                                 >> 2U)))),
                   32,vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data,
                   32,vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10);
    }
    vlSelf->__Vdly__Top__DOT__datapath__DOT__pc = ((IData)(vlSelf->reset)
                                                    ? 0x80000000U
                                                    : 
                                                   (((1U 
                                                      == (IData)(vlSelf->Top__DOT___control_unit_io_control_signals_pc_src)) 
                                                     | ((2U 
                                                         == (IData)(vlSelf->Top__DOT___control_unit_io_control_signals_pc_src)) 
                                                        & (1U 
                                                           == vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0)))
                                                     ? 
                                                    (vlSelf->Top__DOT__datapath__DOT__pc 
                                                     + vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext)
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelf->Top__DOT___control_unit_io_control_signals_pc_src))
                                                      ? 
                                                     (0xfffffffeU 
                                                      & (vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1 
                                                         + vlSelf->Top__DOT__datapath__DOT___extend_io_imm_ext))
                                                      : vlSelf->Top__DOT__datapath__DOT___pc_T)));
}

void VTop___024root___nba_sequent__TOP__1(VTop___024root* vlSelf);
void VTop___024root___nba_sequent__TOP__2(VTop___024root* vlSelf);

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VTop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VTop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

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
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
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
                    VL_FATAL_MT("vsrc/Top.sv", 467, "", "Active region did not converge.");
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
                VL_FATAL_MT("vsrc/Top.sv", 467, "", "NBA region did not converge.");
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
}
#endif  // VL_DEBUG
