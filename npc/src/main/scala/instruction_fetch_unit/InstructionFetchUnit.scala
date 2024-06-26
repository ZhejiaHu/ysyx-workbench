package instruction_fetch_unit

import chisel3._ 
import chisel3.util._ 


class InstructionFetchUnit (addr_width: Int = 32, data_width: Int = 32) extends Module {
  val io = IO(new Bundle {
    val inst_in: DecoupledIO[UInt]    = Flipped(DecoupledIO(UInt(data_width.W)))
    val pc_in: DecoupledIO[UInt]      = Flipped(DecoupledIO(UInt(addr_width.W)))

    val inst_out: DecoupledIO[UInt]   = DecoupledIO(UInt(data_width.W))
    val pc_out: DecoupledIO[UInt]     = DecoupledIO(UInt(addr_width.W))
  })

  io.inst_in.ready  := true.B
  io.pc_in.ready    := true.B 

  io.pc_out.bits  := io.pc_in.bits
  io.pc_out.valid   := io.pc_in.valid && io.pc_out.ready 

  io.inst_out.bits := io.inst_in.bits
  io.inst_out.valid := io.inst_in.valid && io.inst_out.ready
}
