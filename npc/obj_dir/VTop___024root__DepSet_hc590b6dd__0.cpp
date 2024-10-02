// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop__Syms.h"
#include "VTop___024root.h"

extern "C" int pmem_read(int raddr);

VL_INLINE_OPT void VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_read_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

VL_INLINE_OPT void VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_write_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

void VTop___024root____Vdpiexp_Top__DOT__inst_memory__DOT__pc_read_TOP(VTop__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiexp_Top__DOT__inst_memory__DOT__pc_read_TOP\n"); );
    // Init
    // Body
    pc_read__Vfuncrtn = vlSymsp->TOP.Top__DOT__datapath__DOT__pc;
}

extern "C" void terminate_simulation(char exit, int pc);

VL_INLINE_OPT void VTop___024root____Vdpiimwrap_Top__DOT__terminate__DOT__terminate_simulation_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, CData/*7:0*/ exit, IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__terminate__DOT__terminate_simulation_TOP\n"); );
    // Body
    char exit__Vcvt;
    for (size_t exit__Vidx = 0; exit__Vidx < 1; ++exit__Vidx) exit__Vcvt = exit;
    int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    terminate_simulation(exit__Vcvt, pc__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clock) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clock)));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->Top__DOT____Vcellinp__control_unit__io_op) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__Top__DOT____Vcellinp__control_unit__io_op));
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
    vlSelf->__Vtrigrprev__TOP__Top__DOT____Vcellinp__control_unit__io_op 
        = vlSelf->Top__DOT____Vcellinp__control_unit__io_op;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(1U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__1\n"); );
    // Body
    if ((0x73U == (IData)(vlSelf->Top__DOT____Vcellinp__control_unit__io_op))) {
        VTop___024root____Vdpiimwrap_Top__DOT__terminate__DOT__terminate_simulation_TOP(
                                                                                (&(vlSymsp->__Vscope_Top__terminate)), 
                                                                                "vsrc/Top.sv", 0x289U, 
                                                                                (0U 
                                                                                != vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10), vlSelf->Top__DOT__datapath__DOT__pc);
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__2(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__2\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h800442d7__0;
    // Body
    vlSelf->Top__DOT__datapath__DOT__pc = vlSelf->__Vdly__Top__DOT__datapath__DOT__pc;
    if (vlSelf->reset) {
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_0 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_1 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_2 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_3 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_4 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_5 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_6 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_7 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_8 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_9 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_11 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_12 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_13 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_14 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_15 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_16 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_17 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_18 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_19 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_20 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_21 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_22 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_23 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_24 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_25 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_26 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_27 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_28 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_29 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_30 = 0U;
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_31 = 0U;
    } else {
        vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0 
            = (((0x18U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                    >> 2U))) & (8U 
                                                != 
                                                (0x1fU 
                                                 & (vlSelf->Top__DOT___inst_memory_inst 
                                                    >> 2U)))) 
               & (0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                  >> 7U))));
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (~ (IData)((0U != (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                                           >> 7U))))))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_0 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x80U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_1 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x100U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_2 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x180U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_3 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x200U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_4 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x280U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_5 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x300U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_6 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x380U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_7 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x400U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_8 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x480U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_9 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x500U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_10 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x580U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_11 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x600U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_12 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x680U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_13 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x700U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_14 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x780U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_15 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x800U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_16 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x880U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_17 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x900U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_18 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0x980U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_19 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xa00U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_20 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xa80U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_21 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xb00U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_22 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xb80U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_23 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xc00U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_24 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xc80U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_25 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xd00U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_26 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xd80U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_27 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xe00U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_28 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xe80U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_29 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xf00U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_30 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
        if (((IData)(vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__unnamedblk1__DOT___GEN_0) 
             & (0xf80U == (0xf80U & vlSelf->Top__DOT___inst_memory_inst)))) {
            vlSelf->Top__DOT__datapath__DOT__reg_file__DOT__regs_31 
                = vlSelf->Top__DOT__datapath__DOT____Vcellinp__reg_file__io_wr_data;
        }
    }
    vlSelf->Top__DOT__datapath__DOT___pc_T = ((IData)(4U) 
                                              + vlSelf->Top__DOT__datapath__DOT__pc);
    if ((0U != vlSelf->Top__DOT__datapath__DOT__pc)) {
        VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_read_TOP(
                                                                          (&(vlSymsp->__Vscope_Top__inst_memory)), 
                                                                          "vsrc/Top.sv", 0x278U, vlSelf->Top__DOT__datapath__DOT__pc, vlSelf->__Vfunc_Top__DOT__inst_memory__DOT__pmem_read__2__Vfuncout);
        vlSelf->Top__DOT___inst_memory_inst = vlSelf->__Vfunc_Top__DOT__inst_memory__DOT__pmem_read__2__Vfuncout;
    } else {
        vlSelf->Top__DOT___inst_memory_inst = 0U;
    }
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
    vlSelf->Top__DOT____Vcellinp__control_unit__io_op 
        = (0x7fU & vlSelf->Top__DOT___inst_memory_inst);
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
    vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[
        (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                  >> 0x14U))];
    vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd1 
        = vlSelf->Top__DOT__datapath__DOT__reg_file__DOT___GEN[
        (0x1fU & (vlSelf->Top__DOT___inst_memory_inst 
                  >> 0xfU))];
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
        VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_write_TOP(
                                                                           (&(vlSymsp->__Vscope_Top__memory)), 
                                                                           "vsrc/Top.sv", 0x250U, vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0, vlSelf->Top__DOT__datapath__DOT___reg_file_io_rd2, (IData)(vlSelf->Top__DOT__memory__DOT__mask));
        vlSelf->Top__DOT___memory_mem_rd_data = 0U;
    } else if ((1U & ((~ ((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op) 
                          >> 2U)) & (((IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op) 
                                      >> 1U) | (IData)(vlSelf->Top__DOT___control_unit_io_mem_control_signals_mem_op))))) {
        VTop___024root____Vdpiimwrap_Top__DOT__memory__DOT__pmem_read_TOP(
                                                                          (&(vlSymsp->__Vscope_Top__memory)), 
                                                                          "vsrc/Top.sv", 0x253U, vlSelf->Top__DOT__datapath__DOT__alu__DOT__io_result_0, vlSelf->__Vfunc_Top__DOT__memory__DOT__pmem_read__1__Vfuncout);
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
