package datatypes

import chisel3._ 
import chisel3.util._ 


class MemoryControlSignals (mem_control_width: Int) extends Bundle {
	val mem_op						= UInt(mem_control_width.W)
	val unsigned_data 				= Bool()
}
