package datapath

import chisel3._ 
import chisel3.util._ 

/*
* @input io.imm_src:
*		- 000: S-immidiate
* 		- 001: I-immidiate
* 		- 010: B-immidiate
* 		- 011: J-immidiate	
* 		- 111: U-immidiate
*/
class Extend (data_width: Int = 32, imm_src_width: Int = 3) extends Module {
	val io = IO(new Bundle {
		val instruction 	= Input(UInt(data_width.W))
		val imm_src 		= Input(UInt(imm_src_width.W))
		val imm_ext 		= Output(UInt(data_width.W))
	})

	io.imm_ext 				:= Cat(
		io.instruction(31),
		Mux(io.imm_src(2), io.instruction(30, 20), Fill(11, io.instruction(31))),
		Mux(io.imm_src(1) & io.imm_src(0), io.instruction(19, 12), Fill(8, io.instruction(31))),
		Mux(io.imm_src(2) ^ io.imm_src(1), Mux(io.imm_src(0), io.instruction(20), io.instruction(7)), Mux(io.imm_src(2), 0.U, io.instruction(31))),
		Mux(io.imm_src(2), 0.U, io.instruction(30, 25)),
		Mux(io.imm_src(2), 0.U, Mux(io.imm_src(0), io.instruction(24, 21), io.instruction(11, 8))),
		Mux(io.imm_src(1), 0.U, Mux(io.imm_src(0), io.instruction(20), io.instruction(7)))
	)
}
