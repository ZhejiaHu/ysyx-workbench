package control_unit

import chisel3._ 
import chisel3.util._ 
import datatypes._
import javax.xml.transform.OutputKeys

/*
* @wire io.control_signals.imm_src:
*		- 000: S-immidiate
* 		- 001: I-immidiate
* 		- 010: B-immidiate
* 		- 011: J-immidiate	
* 		- 111: U-immidiate
* 		- 101: R-immidiate
*/
class ControlUnit (
	op_width: Int = 7, 
	funct3_width: Int = 3, 
	funct7_width: Int = 7, 
	alu_control_width: Int = 3, 
	pc_src_width: Int = 2,
	imm_src_width: Int = 3, 
	result_src_width: Int = 2,
	mem_control_width: Int = 3
) extends Module {
   val io = IO(new Bundle {
		val funct3 						= Input(UInt(funct3_width.W))
		val funct7 									= Input(UInt(funct7_width.W))
		val op 										= Input(UInt(op_width.W))
		val zero									= Input(Bool())

		val control_signals 						= Output(new ControlSignals(pc_src_width = pc_src_width, imm_src_width = imm_src_width, result_src_width = result_src_width))
		val alu_control_signals						= Output(new ALUControlSignals(alu_control_width = alu_control_width))
		val mem_control_signals 					= Output(new MemoryControlSignals(mem_control_width = mem_control_width))
   })			

   val opcode										= io.op(6, 2)

   // control_signals
   io.control_signals.imm_src						:= MuxLookup(opcode, "b110".U(imm_src_width.W))(Seq(
		"b00000".U									-> "b001".U,		// I-immidiate
   		"b00100".U 									-> "b001".U,		// I-immidiate
		"b11001".U 									-> "b001".U,		// I-immidiate
		"b00101".U 									-> "b111".U,		// U-immidiate
		"b01101".U 									-> "b111".U,		// U-immidiate
		"b01000".U 									-> "b000".U,		// S-immidiate
		"b01100".U 									-> "b101".U,		// R-immidiate
		"b11000".U									-> "b010".U,		// B-immidate
		"b11011".U 									-> "b011".U			// J-immidiate
   ))	
   io.control_signals.pc_src						:= MuxCase("b00".U(pc_src_width.W), Array(
   		(opcode === "b11011".U) 					-> "b01".U(pc_src_width.W),
		(opcode === "b11000".U)						-> "b10".U(pc_src_width.W),
		(opcode === "b11001".U)						-> "b11".U(pc_src_width.W)
   ))
   io.control_signals.result_src					:= MuxCase(0.U(result_src_width.W), Array(
		(opcode === "b00000".U)										-> 1.U(result_src_width.W),
		(opcode === "b11001".U || opcode === "b11011".U)			-> 2.U(result_src_width.W),
		(opcode === "b00101".U)										-> 3.U(result_src_width.W)
   ))
   io.control_signals.alu_src 						:= opcode =/= "b01100".U && opcode =/= "b11000".U
   io.control_signals.reg_wr						:= opcode =/= "b11000".U && opcode =/= "b01000".U

   // alu_control_signals
   io.alu_control_signals.alu_op 					:= MuxCase("b000".U(alu_control_width.W), Array(
   		(
			(opcode === "b00100".U || opcode === "b01100".U) && ((~io.funct3(2) & (io.funct3(1) | ~io.funct3(0))) === 1.U) || 
			 opcode === "b00000".U || opcode === "b01000".U || 
			(opcode === "b11000".U && io.funct3(2) === 1.U)
		)																										-> "b001".U(alu_control_width.W),		// +
		((opcode === "b00100".U || opcode === "b01100".U) && (io.funct3 === "b001".U(funct3_width.W))) 			-> "b010".U(alu_control_width.W),		// <<
		((opcode === "b00100".U || opcode === "b01100".U) && (io.funct3 === "b101".U(funct3_width.W)))			-> "b011".U(alu_control_width.W),      // >>, >>>
		((opcode === "b00100".U || opcode === "b01100".U) && (io.funct3 === "b100".U(funct3_width.W))) 			-> "b100".U(alu_control_width.W),		// ^
		((opcode === "b00100".U || opcode === "b01100".U) && (io.funct3 === "b110".U(funct3_width.W)))			-> "b101".U(alu_control_width.W), 		// |
		((opcode === "b00100".U || opcode === "b01100".U) && (io.funct3 === "b111".U(funct3_width.W)))			-> "b110".U(alu_control_width.W), 		// &
		(opcode === "b11000".U && io.funct3(2, 1) === "b00".U)													-> "b111".U(alu_control_width.W)		// ==	
   ))
   io.alu_control_signals.unsigned_src 				:= (opcode === "b00100".U || opcode === "b01100".U) && (io.funct3 === "b011".U || io.funct3 === "b101".U && io.funct7 === 0.U) || opcode === "b11000".U && (io.funct3(2) & io.funct3(1)) 
   io.alu_control_signals.negate_src2 				:= opcode === "b01100".U && (io.funct3 === "b000".U && io.funct7(5) === 1.U || io.funct3(2, 1) === "b01".U) || opcode === "b00100".U && io.funct3(2, 1) === "b01".U || opcode === "b11000".U && io.funct3(2) === 1.U
   io.alu_control_signals.compare					:= opcode === "b11000".U || (opcode(2, 0) === "b100".U && io.funct3(2, 1) === "b01".U)
   io.alu_control_signals.compare_flip				:= opcode === "b11000".U && io.funct3(0) === 1.U

   // mem_control_signals
   io.mem_control_signals.mem_op 					:= MuxCase(0.U(mem_control_width.W), Array(
   		(opcode === "b00000".U && io.op(1, 0) === "b11".U)			-> Cat(0.U, io.funct3(1, 0)+1.U),
   		(opcode === "b01000".U) 									-> Cat(1.U, io.funct3(1, 0)+1.U)
   ))
   io.mem_control_signals.unsigned_data				:= opcode === "b00000".U && io.funct3(2) === 1.U
}
