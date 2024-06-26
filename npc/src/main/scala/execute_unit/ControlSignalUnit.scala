package execute_unit

import chisel3._ 
import chisel3.util._ 
import datatype._ 


class ControlSignalUnit (
        num_reg: Int = 32, 
        addr_width: Int         = 32, 
        data_width: Int         = 32, 
        reg_addr_width: Int     = 5,
        opcode_width: Int       = 7,
        funct3_width: Int       = 3,
        funct7_width: Int       = 7,
        inst_type_width: Int    = 3
    ) extends Module {
    val io = IO(new Bundle {
        val instruction_decoded: DecoupledIO[Instruction]       = Flipped(DecoupledIO(new Instruction))
        val control_signal: DecoupledIO[ControlSignal]        = DecoupledIO(new ControlSignal)
    })

    io.instruction_decoded.ready    := true.B
    io.control_signal.alu_inop1     := io.instruction_decoded.opcode    =/= "b0010111".U(opcode_width.W)    
    io.control_signal.alu_inop2     := io.instruction_decoded.inst_type === "b000".U(inst_type_width.W) | io.instruction_decoded.inst_type == "b011".U(inst_type_width.W)
    io.control_signal.rd_write      := io.instruction_decoded.inst_type === "b010".U(inst_type_width.W) | io.instruction_decoded.inst_type == "b011".U(inst_type_width.W)
    io.control_signal.rd_alu        := io.instruction_decoded.opcode    =/= "b0110111".U(opcode_width.W)
    io.control_signal.valid         := io.instruction_decoded.valid
 }