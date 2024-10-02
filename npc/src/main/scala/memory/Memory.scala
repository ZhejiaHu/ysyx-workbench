package memory

import chisel3._ 
import chisel3.util._ 


class Memory (maddr_width: Int = 32, data_width: Int = 32, mem_control_width: Int = 3, mem_mask_width: Int = 4) extends BlackBox with HasBlackBoxInline {
	val io = IO(new Bundle {
		val mem_control		= Input(UInt(mem_control_width.W))
		val mem_unsigned 	= Input(Bool())
		val mem_addr 		= Input(UInt(maddr_width.W))
		val mem_wr_data		= Input(UInt(data_width.W))
		
		val mem_rd_data 	= Output(UInt(data_width.W))
	})

	setInline("Memory.sv", 
		s"""
		|module Memory # (
		|	parameter MADDR_WIDTH = 32, 
		|	parameter DATA_WIDTH = 32,
		|	parameter MEM_CONTROL_WIDTH = 3,
		|	parameter MEM_MASK_WIDTH = 4
		|) (
		|	input [MEM_CONTROL_WIDTH-1:0] mem_control,
		|	input mem_unsigned,
		|	input [MADDR_WIDTH-1:0] mem_addr,
		|	input [DATA_WIDTH-1:0] mem_wr_data,
		|	
		|	output reg [DATA_WIDTH-1:0] mem_rd_data
		|);
		|
		|import "DPI-C" context function int pmem_read(input int raddr);
		|import "DPI-C" context function void pmem_write(input int waddr, input int wdata, input byte wmask);
		|
		|reg[MEM_MASK_WIDTH-1:0] mask; 
		|reg[DATA_WIDTH-1:0] bufs;
		|
		|always @(*) begin
		|	mask = {
		|				(mem_addr[1:0] == 2'b11) || ((mem_addr[1:0] == 2'b10) && (mem_control[1:0] == 2'b10)) || (mem_control[1:0] == 2'b11), 
		|				(mem_addr[1:0] == 2'b10) || (mem_control[1:0] == 2'b11), 
		|				(mem_addr[1:0] == 2'b01) || ((mem_addr[1:0] == 2'b00) && (mem_control[1] == 1'b1)), 
		|				(mem_addr[1:0] == 2'b00)
		|	}; 
		|	if (mem_control[2] & (mem_control[1] | mem_control[0])) begin 
		|		pmem_write(mem_addr, mem_wr_data, {4'b0000, mask});
		|		mem_rd_data = 0;
		|	end else if (~mem_control[2] & (mem_control[1] | mem_control[0])) begin 
		|		bufs = pmem_read(mem_addr) & {{8{mask[3]}}, {8{mask[2]}}, {8{mask[1]}}, {8{mask[0]}}};
		|		case (mem_addr[1:0])
		|			2'b01: bufs = bufs >> 8;
		|			2'b10: bufs = bufs >> 16;
		|			2'b11: bufs = bufs >> 24;
		|			default: bufs = bufs;
		|		endcase
		|		case (mem_control[1:0])
		|			2'b01: mem_rd_data = mem_unsigned ? {24'b0, bufs[7:0]} : {{24{bufs[7]}}, bufs[7:0]};
		|			2'b10: mem_rd_data = mem_unsigned ? {16'b0, bufs[15:0]} : {{16{bufs[15]}}, bufs[15:0]};
		|			2'b11: mem_rd_data = bufs;
		|			default: mem_rd_data = 0;
		|		endcase 
		|	end else mem_rd_data = 0;
		|end
		|
		|endmodule
		""".stripMargin)
}
