package datapath

import scala.util.Random

import chisel3._
import chisel3.util._ 
import chisel3.experimental.BundleLiterals._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.must.Matchers

import utility._ 
import utility.Utility._

class ALU_Spec extends AnyFreeSpec with Matchers {
	val data_width: Int = 32
	val alu_control_width: Int = 3

	val num_iter: Int = 2000

	val log: (UIntString[32], UIntString[32], ALUControl, UInt, UInt) => String = (src1, src2, alu_control, circuit_result, solution) => s"""
		- Input: src1 - $src1 | src2 - $src2 | alu_control - $alu_control
		- Output: Circuit - ${circuit_result.peek().litValue} | Expect: ${solution}
	"""
	
	def poke(dut: ALU, src1: UIntString[32], src2: UIntString[32], alu_control: ALUControl): Unit = {
		dut.io.src1.poke(src1.U(len = 32))
		dut.io.src2.poke(src2.U(len = 32))
		dut.io.alu_control_signals.alu_op.poke(alu_control.alu_op.U (len = alu_control_width))
		dut.io.alu_control_signals.unsigned_src.poke(alu_control.unsigned_src)
		dut.io.alu_control_signals.negate_src2.poke(alu_control.negate_src2)
		dut.io.alu_control_signals.compare.poke(alu_control.compare)
		dut.io.alu_control_signals.compare_flip.poke(alu_control.compare_flip)
	}

	def verify_random(): Unit = {
		"Random Input Test" in {
			simulate(new ALU(data_width = data_width, alu_control_width = alu_control_width)) { dut =>
				for (i <- 1 to num_iter) {
					println(s"Testing on iteratoin $i")
					val (src1, src2, alu_control_raw) = ALUTest.random_input()
					val alu_control = ALUTest.correct_alu_control(alu_control_raw)
					poke(dut, src1, src2, alu_control)
					dut.clock.step(1)
					val solution = ALUTest.alu_solve32(src1, src2, alu_control)
					dut.io.result.expect(solution.U(len = 32), log(src1, src2, alu_control, dut.io.result, solution.U(len = 32)))
					println(solution)
					println(log(src1, src2, alu_control, dut.io.result, solution.U(len = 32)))
				}
			}
		}
	}

	def verify(src1: UIntString[32], src2: UIntString[32], alu_control: ALUControl) {
		s"Specific Test" in {
			simulate(new ALU(data_width = data_width, alu_control_width = alu_control_width)) { dut =>
				poke(dut, src1, src2, alu_control)
				dut.clock.step(1)
				val solution = ALUTest.alu_solve32(src1, src2, alu_control)
				dut.io.result.expect(solution.U(len = 32), log(src1, src2, alu_control, dut.io.result, solution.U(len = 32)))
				println(solution)
				println(log(src1, src2, alu_control, dut.io.result, solution.U(len = 32)))
			}
		}
	}

	verify("00000000000000000000000101110111", "10000000000000000000000101110111", ALUControl(alu_op = "011", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false))
	//verify_random()
}
