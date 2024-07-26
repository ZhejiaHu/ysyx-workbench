package datatypes

import chisel3._ 
import chisel3.util._


class ALUControlSignals (alu_control_width: Int) extends Bundle {
	val alu_op				= UInt(alu_control_width.W)
	val unsigned_src		= Bool()
	val negate_src2			= Bool()
	val compare 			= Bool()
	val compare_flip		= Bool()
}
