package instruction_decode_unit

import chisel3._ 
import chisel3.util._ 
import datatype._ 


class InstructionDecodeUnit (
        addr_width: Int         = 32, 
        data_width: Int         = 32, 
        reg_addr_width: Int     = 5,
        opcode_width: Int       = 7,
        funct3_width: Int       = 3,
        funct7_width: Int       = 7,
        inst_type_width: Int    = 3
    ) extends Module {
    val io = IO(new Bundle {
        val inst: DecoupledIO[UInt]                         = Flipped(DecoupledIO(UInt(data_width.W)))

        val instruction_decoded: DecoupledIO[Instruction]   = DecoupledIO(new Instruction)
    })

    io.inst.ready := true.B

    val inst_type: UInt = MuxLookup(io.inst.bits(6, 0), "b111".U(inst_type_width.W)) (Seq(
        "b0010111".U(opcode_width.W)    -> "b100".U(inst_type_width.W),
        "b0010011".U(opcode_width.W)    -> "b001".U(inst_type_width.W),
        "b1110011".U(opcode_width.W)    -> "b110".U(inst_type_width.W),
    ))

    // instruction
    io.instruction_decoded.bit.opcode      := io.inst.bits(6, 0)
    io.instruction_decoded.bit.rd          := io.inst.bits(11, 7)
    io.instruction_decoded.bit.rs1         := io.inst.bits(19, 15)
    io.instruction_decoded.bit.rs2         := io.inst.bits(24, 20)
    io.instruction_decoded.bit.funct3      := io.inst.bits(14, 12)
    io.instruction_decoded.bit.funct7      := io.inst.bits(31, 25)
    io.instruction_decoded.bit.imm         := MuxLookup(inst_type, "hFFFFFFFF".asUInt(data_width.W).asSInt) (Seq(
        "b001".U(inst_type_width.W)   -> io.inst.bits(31, 20).asSInt,
        "b010".U(inst_type_width.W)   -> Cat(io.inst.bits(31, 25), io.inst.bits(11, 7)).asSInt,
        "b011".U(inst_type_width.W)   -> Seq(io.inst.bits(31), io.inst.bits(7), io.inst.bits(30, 25), io.inst.bits(11, 8)).foldRight(0.U(1.W)) (Cat(_, _)).asSInt,
        "b100".U(inst_type_width.W)   -> Cat(io.inst.bits(31, 12), 0.U(12.W)).asSInt,
        "b101".U(inst_type_width.W)   -> Seq(io.inst.bits(31), io.inst.bits(19, 12), io.inst.bits(20), io.inst.bits(30, 21)).foldRight(0.U(1.W)) (Cat(_, _)).asSInt
    ))
    io.instruction_decoded.bits.inst_type   := inst_type

    io.instruction+decoded.valid            := io.inst.valid 
}
