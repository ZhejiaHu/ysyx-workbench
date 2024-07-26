package memory

import chisel3._ 
import chisel3.util._ 


class InstructionMemory (maddr_width: Int = 32, data_width: Int = 32) extends BlackBox with HasBlackBoxInline {
	val io = IO(new Bundle {
		val pc				= Input(UInt(maddr_width.W))
		val inst			= Output(UInt(data_width.W))
	})
  
	setInline("InstructionMemory.sv", 
		s"""
		|module InstructionMemory # (
		|	parameter MADDR_WIDTH = 32, 
		|	parameter DATA_WIDTH = 32
		|) (
		|	input [MADDR_WIDTH-1:0] pc,
		|	output reg [DATA_WIDTH-1:0] inst
		|);
		|import "DPI-C" function int pmem_read(input int raddr);
		|always @(*) begin
		|	if (pc != 0) inst = pmem_read(pc);
		|	else inst = 0;
		|end
		|endmodule
		""".stripMargin)
}
