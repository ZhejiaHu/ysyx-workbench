package datapath

import chisel3._ 
import chisel3.util._
import datatypes._


class Datapath (
	data_width: Int 			= 32,
	alu_control_width: Int  	= 3,
	pc_src_width: Int 			= 2,
	imm_src_width: Int 			= 3, 
	raddr_width: Int 			= 5,
	maddr_width: Int 			= 32,
	num_reg: Int 				= 32,
	result_src_width: Int 		= 2,
	pc_rst: Int					= -2147483648
) extends Module {
	val io = IO(new Bundle{
		val control_signals 		= Input(new ControlSignals(pc_src_width = pc_src_width, imm_src_width = imm_src_width, result_src_width = result_src_width))
		val alu_control_signals 	= Input(new ALUControlSignals(alu_control_width = alu_control_width))
		val instruction 			= Input(UInt(data_width.W))
		val mem_rd_data 			= Input(UInt(data_width.W))

		val mem_addr				= Output(UInt(maddr_width.W))
		val mem_wr_data 			= Output(UInt(data_width.W))
		val zero 					= Output(Bool())
		val pc 						= Output(SInt(maddr_width.W))
		val exit 					= Output(Bool()) 
	})		

	val alu 						= Module(new ALU(data_width = data_width, alu_control_width = alu_control_width))
	val extend 						= Module(new Extend(data_width = data_width, imm_src_width = imm_src_width))
	val reg_file 					= Module(new RegisterFile(raddr_width = raddr_width, data_width = data_width, num_reg = num_reg))
	val pc							= RegInit(pc_rst.S(data_width.W))

	reg_file.io.rs1 				:= io.instruction(19, 15)
	reg_file.io.rs2					:= io.instruction(24, 20)
	reg_file.io.rd 					:= io.instruction(11, 7)
	reg_file.io.wr_en 				:= io.control_signals.reg_wr
	printf(cf"[Datapath] alu.io.result --- 0x${alu.io.result}%x | reg_file.io.rd --- ${reg_file.io.rd} | reg_file.io.wr_en --- ${reg_file.io.wr_en} | io.control_signals.result_src --- ${io.control_signals.result_src} | io.control_signals.pc_src --- ${io.control_signals.pc_src} | alu.io.result --- ${alu.io.result === 1.U(data_width.W)} \n")
	reg_file.io.wr_data 			:= MuxLookup(io.control_signals.result_src, 0.U(data_width.W))(Seq(
		0.U(result_src_width.W)			-> alu.io.result,
		1.U(result_src_width.W) 		-> io.mem_rd_data,
		2.U(result_src_width.W) 		-> (pc + 4.S).asUInt,
		3.U(result_src_width.W)			-> (pc + extend.io.imm_ext.asSInt).asUInt
	))		

	alu.io.src1 					:= reg_file.io.rd1 
	alu.io.src2 					:= Mux(io.control_signals.alu_src, extend.io.imm_ext, reg_file.io.rd2)
	alu.io.alu_control_signals		:= io.alu_control_signals

	extend.io.instruction			:= io.instruction
	extend.io.imm_src 				:= io.control_signals.imm_src

	io.zero 						:= alu.io.zero 
	io.mem_addr						:= alu.io.result
	io.mem_wr_data					:= reg_file.io.rd2
	io.pc 							:= pc
	io.exit							:= reg_file.io.exit

	pc								:= MuxCase(pc + 4.S, Array(
		(io.control_signals.pc_src === "b01".U(pc_src_width.W) || io.control_signals.pc_src === "b10".U(pc_src_width.W) && alu.io.result === 1.U(data_width.W))	-> (pc + extend.io.imm_ext.asSInt),
		(io.control_signals.pc_src === "b11".U(pc_src_width.W))												-> ((reg_file.io.rd1.asSInt + extend.io.imm_ext.asSInt).asUInt & Cat(Fill(data_width - 1, 1.U), 0.U)).asSInt							
	))


}

