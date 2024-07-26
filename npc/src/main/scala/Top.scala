import chisel3._ 
import chisel3.util._
import control_unit.ControlUnit
import datapath.Datapath
import memory.Memory
import memory.InstructionMemory


class Top (
	op_width: Int 				= 7,
	funct3_width: Int 			= 3,
	funct7_width: Int 			= 7,
	data_width: Int 			= 32,
	alu_control_width: Int 		= 3,
	pc_src_width: Int 			= 2,
	imm_src_width: Int 			= 3, 
	raddr_width: Int 			= 5,
	maddr_width: Int 			= 32,
	num_reg: Int 				= 32,
	result_src_width: Int 		= 2,
	mem_control_width: Int 		= 3,
	pc_rst: Int					= -2147483648
) extends Module {
	
	val datapath 						= Module(new Datapath(
		data_width = data_width, 
		alu_control_width = alu_control_width, 
		pc_src_width = pc_src_width,
		imm_src_width = imm_src_width, 
		raddr_width = raddr_width, 
		maddr_width = maddr_width, 
		num_reg = num_reg, 
		pc_rst = pc_rst, 
		result_src_width = result_src_width
	))

	val control_unit 					= Module(new ControlUnit(
		op_width = op_width, 
		funct3_width = funct3_width, 
		funct7_width = funct7_width, 
		alu_control_width = alu_control_width, 
		imm_src_width = imm_src_width
	))

	val memory 							= Module(new Memory(maddr_width = maddr_width, data_width = data_width, mem_control_width = mem_control_width))

	val inst_memory						= Module(new InstructionMemory(maddr_width = maddr_width, data_width = data_width))				

	val terminate 						= Module(new Terminate(data_width = data_width, op_width = op_width))

	terminate.io.op 					:= inst_memory.io.inst(6, 0) 
	terminate.io.exit					:= datapath.io.exit
	terminate.io.pc 					:= datapath.io.pc.asUInt

	datapath.io.control_signals  		:= control_unit.io.control_signals
	datapath.io.alu_control_signals		:= control_unit.io.alu_control_signals
	datapath.io.instruction 			:= inst_memory.io.inst
	datapath.io.mem_rd_data 			:= memory.io.mem_rd_data

	control_unit.io.funct3				:= inst_memory.io.inst(14, 12)
	control_unit.io.funct7 				:= inst_memory.io.inst(31, 25)
	control_unit.io.op 					:= inst_memory.io.inst(6, 0)
	control_unit.io.zero 				:= datapath.io.zero

	memory.io.mem_control				:= control_unit.io.mem_control_signals.mem_op
	memory.io.mem_unsigned 				:= control_unit.io.mem_control_signals.unsigned_data
	memory.io.mem_addr 					:= datapath.io.mem_addr
	memory.io.mem_wr_data				:= datapath.io.mem_wr_data
	inst_memory.io.pc 					:= datapath.io.pc.asUInt 


	printf("[Top] io.instruction = 0x%x | io.pc = 0x%x\n", inst_memory.io.inst, datapath.io.pc)
}
