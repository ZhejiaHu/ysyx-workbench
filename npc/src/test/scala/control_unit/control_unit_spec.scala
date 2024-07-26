package control_unit

import scala.util.Random

import chisel3._
import chisel3.util._ 
import chisel3.experimental.BundleLiterals._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.must.Matchers

import utility._ 
import utility.Utility._


class ControlUnit_Spec extends AnyFreeSpec with Matchers {
	val op_width: Int 			= 7
	val funct3_width: Int 		= 3 
	val funct7_width: Int 		= 7 
	val pc_src_width: Int 		= 2
	val alu_control_width: Int 	= 3
	val imm_src_width: Int 		= 3
	val data_width: Int 		= 32
	val result_src_width: Int 	= 2
	val mem_control_width: Int  = 3

	val num_iter: Int 			= 20


	def poke(dut: ControlUnit, inst: UInt): Unit = {
		dut.io.op.poke(inst(6, 0))
		dut.io.funct3.poke(inst(14, 12))
		dut.io.funct7.poke(inst(31, 25))
		dut.io.zero.poke(false.B)
	}

	def verify_alu_control(dut: ControlUnit, alu_control: ALUControl): Unit = {
		dut.io.alu_control_signals.alu_op.expect(alu_control.alu_op.U(len = alu_control_width), "[ALU Control] alu_op")
		dut.io.alu_control_signals.unsigned_src.expect(alu_control.unsigned_src.B, "[ALU Control] unsigned_src")
		dut.io.alu_control_signals.negate_src2.expect(alu_control.negate_src2.B, "[ALU Control] negate_src2")
		dut.io.alu_control_signals.compare.expect(alu_control.compare.B, "[ALU Control] compare")
		dut.io.alu_control_signals.compare_flip.expect(alu_control.compare_flip.B, "[ALU Control] compare_flip")
	}

	def verify_mem_control(dut: ControlUnit, mem_control: MemoryControl): Unit = {
		dut.io.mem_control_signals.mem_op.expect(mem_control.mem_op.U(len = mem_control_width), "[Memory Contol] mem_op")
		dut.io.mem_control_signals.unsigned_data.expect(mem_control.unsigned_data.B, "[Memory Control] unsigned_data")
	}

	def verify_control(dut: ControlUnit, control: Control): Unit = {
		dut.io.control_signals.pc_src.expect(control.pc_src.U(len = pc_src_width), "[Control] pc_src")
		dut.io.control_signals.result_src.expect(control.result_src.U(len = result_src_width), "[Control] result_src")
		dut.io.control_signals.alu_src.expect(control.alu_src.B, "[Control] alu_src")
		dut.io.control_signals.imm_src.expect(control.imm_src.U(len = imm_src_width), "[Control] imm_src")
		dut.io.control_signals.reg_wr.expect(control.reg_wr.B, "[Control] reg_wr")
	}


	def simulate_test(inst_name: String): Unit = {
		s"[instruction ${inst_name} test]" in {
			simulate(new ControlUnit(op_width = op_width, funct3_width = funct3_width, funct7_width = funct7_width, alu_control_width = alu_control_width, imm_src_width = imm_src_width)) { dut =>
				for (i <- 0 to num_iter) {
					val inst: UIntString[32] = RandomInstruction.random_instruction(inst_name)
					poke(dut, inst.U(len = 32))
					dut.clock.step(1)
					val solution: ControlUnitOutputs = ControlUnitSolution.control_signals32(inst)
					verify_alu_control(dut, solution.alu_control)
					verify_mem_control(dut, solution.mem_control)
					verify_control(dut, solution.control)
				}
			}
		}
	}

	// I-instruction
	//simulate_test("addi")
	//simulate_test("slli")
	//simulate_test("slti")
	//simulate_test("sltiu")
	simulate_test("srai")
	//simulate_test("andi")
	//simulate_test("lbu")

	// R-instruction
	//simulate_test("add")
	//simulate_test("sll")
	//simulate_test("sltu")
	//simulate_test("and")
	
	// B-instruction
	//simulate_test("bne")
	//simulate_test("bge")
	//simulate_test("bgeu")

	// U-instruction
	//simulate_test("auipc")
	//simulate_test("lui")
}
