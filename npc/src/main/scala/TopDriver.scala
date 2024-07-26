import chisel3._
import chisel3.stage.ChiselGeneratorAnnotation
import circt.stage.{ChiselStage, FirtoolOption}


object TopDriver extends App {
	(new ChiselStage).execute(Array("--target", "systemverilog", "--target-dir", "vsrc"), Seq(ChiselGeneratorAnnotation(() => new Top), FirtoolOption("--disable-all-randomization")))
}