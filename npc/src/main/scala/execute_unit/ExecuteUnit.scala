package execute_unit

import chisel3._ 
import chisel3.util._ 

import datatype._ 
import register_file._ 
import utility._


class ExecuteUnit (
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
        val read_mem_data: DecoupledIO[UInt]                    = Flipped(DecoupledIO(UInt(data_width.W)))
        val cur_pc: DecoupledIO[UInt]                           = Flipped(DecoupledIO(UInt(data_width.W)))

        val write_mem_bundle: DecoupledIO[WriteBundle]          = DecoupledIO(new WriteBundle(addr_width = addr_width, data_width = data_width))
        val write_mem: DecoupledIO[Bool]                        = DecoupledIO(Bool())
        val inc_pc: DecoupledIO[Bool]                           = DecoupledIO(Bool())
        val dynamic_pc: DecoupledIO[UInt]                       = DecoupledIO(UInt(addr_width.W))
    })

    val arithmetic_logic_unit: ArithmeticLogicUnit                      = Module(new ArithmeticLogicUnit(data_width, opcode_width, funct3_width, funct7_width))
    val register_file: RegisterFile                                     = Module(new RegisterFile(num_reg, 5, data_width))
    val simulation_termination: SimulationTermination_BlackBox_Inline   = Module(new SimulationTermination_BlackBox_Inline(opcode_width))
    val control_signal_unit: ControlSignalUnit                          = Module(new ControlSignalUnit)

    // Set the ready of the input signal to true
    io.instruction.ready                                 := true.B 
    io.cur_pc.ready                                      := true.B

    register_file.io.read_addr_1.bits                    := io.instruction_decoded.rs1
    register_file.io.read_addr_1.valid                   := io.instruction_decoded.valid 
    register_file.io.read_addr_2.bits                    := io.instruction_decoded.rs2 
    register_file.io.read_addr_2.valid                   := io.instruction_decoded.valid 

    // Connect the output of instruction decoder to control signal 
    control_signal_unit.io.instruction_decoded           <> io.instruction_decoded
    val pass_alu: Bool                                   = control_signal_unit.io.control_signal.valid & control_signal_unit.io.control_signal.bits.use_alu
    arithmetic_logic_unit.io.out_operand.ready           := pass_alu
    arithmetic_logic_unit.io.input.valid                 := pass_alu
    arithmetic_logic_unit.io.input.bits.opcode           := io.instruction_decoded.bits.opcode
    arithmetic_logic_unit.io.input.bits.funct3           := io.instruction_decoded.bits.funct3 
    arithmetic_logic_unit.io.input.bits.funct7           := io.instruction_decoded.bits.funct7
    arithmetic_logic_unit.io.input.bits.in_operand_1     := Mux(control_signal_unit.io.control_signal.bits.alu_inop1, register_file.read_data_1, cur_pc.bits)
    arithmetic_logic_unit.io.input.bits.in_operand_2     := Mux(control_signal_unit.io.control_signal.bits.alu_inop2, register_file.read_data_2, io.instruction_decoded.bits.imm)

    // Set the write bundle of the register (address + data) and ready signal for register file read data port 2
    register_file.io.write_bundle.bits.write_addr        := io.rd.bits
    register_file.io.write_bundle.bits.write_data        := Mux(control_signal_unit.io.control_signal.bits.rd_alu, arithmetic_logic_unit.io.out_operand.bits.U(data_width.W), Cat(io.imm.bits, 0.U(12.W)))
    register_file.io.write_bundle.valid                  := control_signal_unit.io.control_signal.bits.rd_write

    register_file.io.write.bits                          := ~io.inst_type.bits(1) // Instruction type is not S-type or B-type
    register_file.io.write.valid                         := write_reg_valid

    register_file.io.read_data_2.ready                   := true.B

    // Set the next program counter
    io.inc_pc.valid                     := io.inc_pc.ready && io.inst_type.valid
    io.inc_pc.bits                      := ~((io.inst_type.bits(2) ^ io.inst_type.bits(1)) && io.inst_type.bits(0))

    // Set the dynamic PC to DontCare
    io.dynamic_pc                       <> DontCare

    // Set the memory read / memory operation to DontCare for this assignment.
    io.write_mem_bundle                 <> DontCare
    io.write_mem                        <> DontCare
    io.read_mem_data                    <> DontCare

    // simulation terminate (for opcode ebreak)
    simulation_termination.io.opcode    := Mux(io.opcode.valid, io.opcode.bits, 0.U(opcode_width.W))
}
