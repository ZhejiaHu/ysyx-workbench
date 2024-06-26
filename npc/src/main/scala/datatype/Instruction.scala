package datatype

import chisel3._ 
import chisel3.util._ 


class Instruction (
    data_width: Int         = 32, 
    reg_addr_width: Int     = 5,
    opcode_width: Int       = 7,
    funct3_width: Int       = 3,
    funct7_width: Int       = 7,
    inst_type_width: Int    = 3
) {
    val opcode: UInt                           = UInt(opcode_width.W)
    val funct3: UInt                           = UInt(funct3_width.W)
    val funct7: UInt                           = UInt(funct7_width.W)
    val rs1: UInt                              = UInt(reg_addr_width.W)
    val rs2: UInt                              = UInt(reg_addr_width.W)
    val rd: UInt                               = UInt(reg_addr_width.W)
    val imm: UInt                              = SInt(data_width.W)
    val inst_type: UInt                        = UInt(inst_type_width.W)
}



