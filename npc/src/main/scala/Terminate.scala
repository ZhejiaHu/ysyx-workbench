import chisel3._ 
import chisel3.util._ 


class Terminate (data_width: Int = 32, op_width: Int = 7) extends BlackBox with HasBlackBoxInline {
	val io = IO(new Bundle {
		val op 			= Input(UInt(op_width.W))
		val exit 		= Input(Bool())
		val pc			= Input(UInt(data_width.W))
	})
	
	setInline("Terminate.sv", 
        s"""
        |module Terminate # (parameter DATA_WIDTH = 32, parameter OP_WIDTH = 7) (
        |    input [OP_WIDTH - 1:0] op,   
		|    input exit,
		|	 input [DATA_WIDTH - 1:0] pc
        |);
        |import "DPI-C" function void terminate_simulation(input byte exit, input int pc);
        |always @ (op) begin 
        |    if (op == 7'b1110011) terminate_simulation({7'b0, exit}, pc);
        |end
        |endmodule         
        """.stripMargin)
}
