package top

import chisel3._ 
import chisel3.util._ 


object TopDriver extends App {
    emitVerilog(
        new Top, 
        Array("--target-dir", "vsrc/")
    )
}
