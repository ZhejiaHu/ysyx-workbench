package datatype

import chisel3._ 
import chisel3.util._ 

// First use minimum bit if more information is needed, will increase bit length
class ControlSignal {
  val use_alu: Bool     = Bool()    // True -> use alu            | False -> not use alu
  val alu_inop1: Bool   = Bool()    // True -> rs1                | False -> pc 
  val alu_inop2: Bool   = Bool()    // True -> rs2                | False -> imm
  val rd_write: Bool    = Bool()    // True -> rd will be written | False -> rd will not be written
  val rd_alu: Bool      = Bool()    // True -> alu                | False -> other methods 
}
