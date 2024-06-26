package top 

import chisel3._ 
import chisel3.util._ 

import execute_unit._ 
import instruction_decode_unit._
import instruction_fetch_unit._ 
import register_file._ 


class Top (num_reg: Int = 32, addr_width: Int = 32, data_width: Int = 32, init_pc_str: String = "h80000000", word_size: Int = 4) extends Module {
  val io = IO(new Bundle {
    val inst: DecoupledIO[UInt] = Flipped(DecoupledIO(UInt(data_width.W)))

    val pc: DecoupledIO[UInt]   = DecoupledIO(UInt(addr_width.W))
  })

  val instruction_fetch_unit: InstructionFetchUnit    = Module(new InstructionFetchUnit(addr_width, data_width))
  val program_counter: ProgramCounter                 = Module(new ProgramCounter(addr_width, init_pc_str, word_size))
  val instruction_decode_unit: InstructionDecodeUnit  = Module(new InstructionDecodeUnit(addr_width = addr_width, data_width = data_width))
  val execute_unit: ExecuteUnit                       = Module(new ExecuteUnit(num_reg, addr_width, data_width))

  // Connections with instruction_fetch_unit
  io.inst.ready                                       := true.B
  instruction_fetch_unit.io.pc_in                     <> program_counter.io.pc_out
  instruction_fetch_unit.io.pc_out                    <> io.pc
  instruction_fetch_unit.io.inst_in                   <> io.inst

  // Connection with instruction_decode_unit
  instruction_decode_unit.io.inst                     <> instruction_fetch_unit.io.inst_out

  // Connect instruction_decode_unit with execute_unit
  execute_unit.io.opcode                              <> instruction_decode_unit.io.opcode 
  execute_unit.io.funct3                              <> instruction_decode_unit.io.funct3
  execute_unit.io.funct7                              <> instruction_decode_unit.io.funct7
  execute_unit.io.rs1                                 <> instruction_decode_unit.io.rs1 
  execute_unit.io.rs2                                 <> instruction_decode_unit.io.rs2
  execute_unit.io.rd                                  <> instruction_decode_unit.io.rd 
  execute_unit.io.imm                                 <> instruction_decode_unit.io.imm 
  execute_unit.io.inst_type                           <> instruction_decode_unit.io.inst_type
  execute_unit.io.cur_pc                              <> io.pc 

  // Updating PC related code
  program_counter.io.inc                              <> execute_unit.io.inc_pc
  program_counter.io.pc_in                            <> execute_unit.io.dynamic_pc

  // DontCare the memory signal
  execute_unit.io.write_mem_bundle.ready              := DontCare
  execute_unit.io.write_mem.ready                     := DontCare
  execute_unit.io.read_mem_data                       <> DontCare
}
