package datapath

import chisel3._ 
import chisel3.util._ 
import java.nio.file.Path


class RegisterFile (raddr_width: Int = 5, data_width: Int = 32, num_reg: Int = 32) extends Module {
	val io = IO(new Bundle {
		val rs1 		= Input(UInt(raddr_width.W))
		val rs2 		= Input(UInt(raddr_width.W))
		val rd 			= Input(UInt(raddr_width.W))
		val wr_data 	= Input(UInt(data_width.W))
		val wr_en		= Input(Bool())

		val rd1			= Output(UInt(data_width.W))
		val rd2			= Output(UInt(data_width.W))
		val exit 		= Output(Bool())
	})
	
	val regs = RegInit(VecInit(Seq.fill(num_reg)(0.U(data_width.W))))

	io.rd1 		:= regs(io.rs1)
	io.rd2 		:= regs(io.rs2)
	io.exit 	:= regs(10) =/= 0.U(data_width.W)
	
	when (io.wr_en && io.rd =/= 0.U(raddr_width.W)) {
		regs(io.rd) := io.wr_data   
	}
	
	printf(cf"[RegisterFile] io.rd : ${io.rd} | io.wr_en : ${io.wr_en} | io.wr_data : ${io.wr_data}\n")
	printf(cf"[RegisterFile] Register 10 (a0): 0x${regs(10)}%x\n")
	//for (i <- 0 until num_reg) {
	//	printf("Register %d: 0x%x\n", i.asUInt, regs(i))
	//}


}
