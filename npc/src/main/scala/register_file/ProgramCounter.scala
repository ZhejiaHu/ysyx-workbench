package register_file

import chisel3._ 
import chisel3.util._ 


class ProgramCounter (addr_width: Int = 32, init_pc_str: String = "h80000000", word_size: Int = 4) extends Module {
  val init_pc: UInt = init_pc_str.U(addr_width.W)
  val io = IO(new Bundle {
    val inc: DecoupledIO[Bool]      = Flipped(DecoupledIO(Bool()))
    val pc_in: DecoupledIO[UInt]    = Flipped(DecoupledIO(UInt(addr_width.W)))

    val pc_out: DecoupledIO[UInt]   = DecoupledIO(UInt(addr_width.W))
  })

  io.inc.ready      := true.B
  io.pc_in.ready    := true.B

  val program_counter: UInt = RegInit(init_pc)

  printf(cf"[ProgramCounter.scala] init_pc_str : ${init_pc_str} | init_pc : ${init_pc} | program_counter : ${program_counter} | io.inc.valid : ${io.inc.valid} | io.pc_in.valid : ${io.pc_in.valid}\n");

  program_counter := MuxCase(program_counter, Array(
    (io.inc.valid && ~io.pc_in.valid) -> (program_counter + word_size.U(addr_width.W)),
    (~io.inc.valid && io.pc_in.valid) -> io.pc_in.bits
  ))

  io.pc_out.bits   := program_counter  
  io.pc_out.valid  := io.pc_out.ready
}
