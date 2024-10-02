// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "VTop.h"
#include "VTop__Syms.h"
#include "verilated_dpi.h"


int VTop::pc_read() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root::pc_read\n"); );
    // Init
    IData/*31:0*/ pc_read__Vfuncrtn__Vcvt;
    pc_read__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("pc_read");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VTop__Vcb_pc_read_t __Vcb = (VTop__Vcb_pc_read_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VTop__Syms*)(__Vscopep->symsp()), pc_read__Vfuncrtn__Vcvt);
    int pc_read__Vfuncrtn;
    for (size_t pc_read__Vfuncrtn__Vidx = 0; pc_read__Vfuncrtn__Vidx < 1; ++pc_read__Vfuncrtn__Vidx) pc_read__Vfuncrtn = pc_read__Vfuncrtn__Vcvt;
    return pc_read__Vfuncrtn;
}
