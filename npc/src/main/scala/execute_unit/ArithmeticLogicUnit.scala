package execute_unit

import chisel3._ 
import chisel3.util._ 
import datatype._ 


class ArithmeticLogicUnit (data_width: Int = 32, opcode_width: Int = 7, funct3_width: Int = 3, funct7_width: Int = 7) extends Module {
    val DEFAULT_OUTPUT: UInt = 0.U(data_width.W)
    
    val io = IO(new Bundle {
        val input: DecoupledIO              = Flipped(DecoupledIO(new ALUInput))
        val out_operand: DecoupledIO[UInt]  = DecoupledIO(UInt(data_width.W))
    })

    io.input.ready          := true.B

    
    // io.out_operand.bits     := MuxLookup(io.opcode.bits, DEFAULT_OUTPUT) (Seq(
    //     "b0010111".U(opcode_width.W)    -> io.in_operand_1.bits + Cat(io.in_operand_2.bits, 0.U(12.W)),               // AUIPC
    //     "b0010011".U(opcode_width.W)    -> MuxLookup(io.funct3.bits, DEFAULT_OUTPUT) (Seq(
    //         "b000".U(funct3_width.W)        -> (io.in_operand_1.bits + io.in_operand_2.bits)                    // ADDI
    //     ))
    // ))
// 
    // io.out_operand.valid    := io.out_operand.ready && io.input.valid 
}
