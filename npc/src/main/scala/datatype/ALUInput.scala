package datatype

import chisel3._ 
import chisel3.util._ 


class ALUInput (
    data_width: Int         = 32, 
    opcode_width: Int       = 7,
    funct3_width: Int       = 3,
    funct7_width: Int       = 7,
) {
    val in_operand_1: UInt = UInt(data_width.W)
    val in_operand_2: UInt = UInt(data_width.W)
    val opcode: UInt       = UInt(opcode_width.W)
    val funct3: UInt       = UInt(funct3_width.W)
    val funct7: UInt       = UInt(funct7_width.W)
}
