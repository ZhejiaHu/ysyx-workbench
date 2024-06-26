package utility

import chisel3._ 
import chisel3.util._ 
import chisel3.experimental._ 


class SimulationTermination_BlackBox_Inline (reg_width: Int = 7) extends BlackBox with HasBlackBoxInline {
    val io = IO(new Bundle {
        val opcode: UInt = Input(UInt(reg_width.W))
    })
    setInline("./SimulationTermination_BlackBox_Inline.sv", 
        s"""
        |module SimulationTermination_BlackBox_Inline # (OPCODE_WIDTH = 7) (
        |    input [OPCODE_WIDTH - 1:0] opcode    
        |);
        |import "DPI-C" function void terminate_simulation();
        |function void terminate();
        |    terminate_simulation();
        |endfunction;
        |always @ (opcode) begin 
        |    if (opcode == 7'b1110011) terminate();
        |end
        |endmodule         
        """.stripMargin)
  
}
