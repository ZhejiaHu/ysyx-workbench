package datatypes

import chisel3._ 
import chisel3.util._ 


class ControlSignals (pc_src_width: Int, imm_src_width: Int, result_src_width: Int) extends Bundle {
	val pc_src			= UInt(pc_src_width.W)
	val result_src		= UInt(result_src_width.W)
	val alu_src			= Bool()
	val imm_src 		= UInt(imm_src_width.W)
	val reg_wr			= Bool()
}
