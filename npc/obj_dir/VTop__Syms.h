// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VTop.h"

// INCLUDE MODULE CLASSES
#include "VTop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VTop__Vcb_pc_read_t = void (*) (VTop__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read__Vfuncrtn);

// SYMS CLASS (contains all model state)
class VTop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VTop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VTop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_Top__inst_memory;
    VerilatedScope __Vscope_Top__memory;
    VerilatedScope __Vscope_Top__terminate;

    // CONSTRUCTORS
    VTop__Syms(VerilatedContext* contextp, const char* namep, VTop* modelp);
    ~VTop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
