package top 

import chisel3._
import chiseltest._
import org.scalatest.freespec.AnyFreeSpec
import chisel3.experimental.BundleLiterals._


class TopTest extends AnyFreeSpec with ChiselScalatestTester {
    val DATA_WIDTH: Int     = 32
    val WORD_SIZE: Int      = 4
    def send_addi_inst(dut: Top, inst: UInt, curr_clk: UInt): Unit = {
        dut.io.inst.bits.poke(inst)
        dut.io.pc.ready.poke(true.B)
        dut.io.inst.valid.poke(true.B)
        dut.clock.step(1)
        dut.io.pc.bits.expect(curr_clk)
        dut.io.pc.valid.expect(true.B)
    }


    // 00440413: addi	s0,s0,4         |-> x8 = 4
    // 27470713: addi	a4,a4,628       |-> x14 = 628
    // 00158593: addi	a1,a1,1         |-> x11 = 1
    // 1dc68693: addi	a3,a3,476       |-> x13 = 476
    // 01868693: addi   a3,a3,24        |-> x13 = 500
    // 03268793: addi   a5,a3,50        |-> x15 = 550
    // f6a78793: addi   a5,a5,-150      |-> x15 = 400
    // ff558593: addi   a1,a1,-11       |-> x11 = -10
    // 0c760613: addi   a2,a2,199       |-> x12 = 199
    // 2cd60693: addi   a3,a2,717       |-> x13 = 916

    "[Top Test]: Test no runtime error of the circuit." in {
        test (new Top) { dut => 
            send_addi_inst(dut, "h00440413".U(DATA_WIDTH.W), "h80000004".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h27470713".U(DATA_WIDTH.W), "h80000008".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h00158593".U(DATA_WIDTH.W), "h8000000C".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h1dc68693".U(DATA_WIDTH.W), "h80000010".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h01868693".U(DATA_WIDTH.W), "h80000014".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h03268793".U(DATA_WIDTH.W), "h80000018".U(DATA_WIDTH.W))
            send_addi_inst(dut, "hf6a78793".U(DATA_WIDTH.W), "h8000001C".U(DATA_WIDTH.W))
            send_addi_inst(dut, "hff558593".U(DATA_WIDTH.W), "h80000020".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h0c760613".U(DATA_WIDTH.W), "h80000024".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h2cd60693".U(DATA_WIDTH.W), "h80000028".U(DATA_WIDTH.W))
            send_addi_inst(dut, "h2cd60693".U(DATA_WIDTH.W), "h8000002C".U(DATA_WIDTH.W))
        }
    }
  
}
