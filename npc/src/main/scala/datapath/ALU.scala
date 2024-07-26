package datapath

import chisel3._ 
import chisel3.util._
import datatypes.ALUControlSignals 


class ALU (data_width: Int = 32, alu_control_width: Int = 3) extends Module {
	val io = IO(new Bundle {
		val src1 					= Input(UInt(data_width.W))
		val src2 					= Input(UInt(data_width.W))
		val alu_control_signals		= Input(new ALUControlSignals(alu_control_width = alu_control_width))

		val zero 					= Output(Bool())
		val result 					= Output(UInt(data_width.W))
	})
	

	val src1 						= Wire(SInt((data_width + 1).W))
	val src2_ 						= Wire(SInt((data_width + 1).W))
	val src2   						= Wire(SInt((data_width + 1).W))
	val result 						= Wire(SInt((data_width + 1).W))

	src1							:= Mux(io.alu_control_signals.unsigned_src, Cat(0.U, io.src1), Cat(io.src1(data_width - 1), io.src1)).asSInt
	src2_							:= Mux(io.alu_control_signals.unsigned_src, Cat(0.U, io.src2), Cat(io.src2(data_width - 1), io.src2)).asSInt
	src2 							:= Mux(io.alu_control_signals.negate_src2, ~src2_ + 1.S, src2_)

	printf(cf"[ALU] src1 --- 0x$src1%x | src2 --- 0x$src2%x | io.alu_control_signals.alu_op --- 0x${io.alu_control_signals.alu_op}%x | io.alu_control_signals.compare --- 0x${io.alu_control_signals.compare}%x | io.alu_control_signals.compare_flip --- 0x${io.alu_control_signals.compare_flip}%x | io.result --- 0x${io.result}%x\n")
	result							:= MuxLookup(io.alu_control_signals.alu_op, src2)(Seq(
		"b001".U(alu_control_width.W) 		-> (src1 + src2),
		"b010".U(alu_control_width.W) 		-> (src1 << src2(4, 0)),
		"b011".U(alu_control_width.W) 		-> (src1 >> src2(4, 0)),
		"b100".U(alu_control_width.W) 		-> (src1 ^ src2),
		"b101".U(alu_control_width.W) 		-> (src1 | src2),
		"b110".U(alu_control_width.W) 		-> (src1 & src2),
		"b111".U(alu_control_width.W) 		-> Cat(Fill(data_width + 1, src1 === src2)).asSInt
	))

	io.zero 						:= result === 0.S((data_width + 1).W) 
	io.result 						:= Mux(io.alu_control_signals.compare, Cat(Fill(data_width - 1, 0.U), Mux(io.alu_control_signals.compare_flip, ~result(data_width), result(data_width))), result(data_width - 1, 0)).asUInt
}
