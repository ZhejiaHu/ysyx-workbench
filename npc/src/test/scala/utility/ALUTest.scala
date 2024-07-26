package utility

import scala.util.Random


object ALUTest {
	val random = new Random()
	val bound = 2000000

	private val _xor: (Char, Char) => Char = (b1, b2) => if (b1 != b2) '1' else '0'
	private val _and: (Char, Char) => Char = (b1, b2) => if (b1 == '1' && b2 == '1') '1' else '0'
	private val _or: (Char, Char) => Char = (b1, b2) => if (b1 == '0' && b2 == '0') '0' else '1' 


	val random_input: () => (UIntString[32], UIntString[32], ALUControl) = () => (Utility.binstring32(random.nextInt(bound) - bound / 2, signed = true), Utility.binstring32(random.nextInt(bound) - bound / 2, signed = true), ALUControl(Utility.random_binstring(3), random.nextBoolean(), random.nextBoolean(), random.nextBoolean(), random.nextBoolean()))

	def correct_alu_control(alu_control: ALUControl): ALUControl = alu_control match {
		case ALUControl(UIntString("000"), _, _, _, _) => ALUControl(UIntString("000"), false, false, false, false)
		case ALUControl(UIntString("001"), _, false, _, _) => ALUControl(UIntString("001"), false, false, false, false)
		case ALUControl(UIntString("001"), _, true, false, _) => ALUControl(UIntString("001"), false, true, false, false)
		case ALUControl(UIntString("010"), _, _, _, _) => ALUControl(UIntString("010"), false, false, false, false)
		case ALUControl(UIntString("011"), unsigned_src, _, _, _) => ALUControl(UIntString("011"), unsigned_src, false, false, false)
		case ALUControl(alu_op, _, _, _, _) if Set(UIntString[3]("100"), UIntString[3]("101"), UIntString[3]("110")).contains(alu_op) => ALUControl(alu_op, false, false, false, false)
		case ALUControl(UIntString("111"), _, _, _, compare_flip) => ALUControl(UIntString("111"), false, false, true, compare_flip)
		case other => other 
	}

	def alu_solve32(src1: UIntString[32], src2: UIntString[32], alu_control: ALUControl): UIntString[32] = alu_control match {
		case ALUControl(UIntString("000"), _, _, _, _) => src2
		case ALUControl(UIntString("001"), _, false, _, _) => Utility.binstring32(num = src1.toInt(signed = true).toInt + src2.toInt(signed = true).toInt, signed = true)
		case ALUControl(UIntString("001"), _, true, false, _) => Utility.binstring32(num = src1.toInt(signed = true).toInt - src2.toInt(signed = true).toInt, signed = true)
		case ALUControl(UIntString("001"), unsigned_src, true, true, compare_flip) => Utility.binstring32(num = if (compare_flip) true.compare(src1.toInt(signed = !unsigned_src) < src2.toInt(signed = !unsigned_src)) else true.compare(src1.toInt(signed = !unsigned_src) >= src2.toInt(signed = !unsigned_src)), signed = false)
		case ALUControl(UIntString("010"), _, _, _, _) => src1 << src2.slice[5](4, 0).toInt(signed = false).toInt
		case ALUControl(UIntString("011"), unsigned_src, _, _, _) => if (unsigned_src) src1 >> src2.slice[5](4, 0).toInt(signed = false).toInt else src1 >>> src2.slice[5](4, 0).toInt(signed = false).toInt
		case ALUControl(UIntString("100"), _, _, _, _) => (src1 zip src2).map{ case (ch1, ch2) => _xor(ch1, ch2) }.mkString
		case ALUControl(UIntString("101"), _, _, _, _) => (src1 zip src2).map{ case (ch1, ch2) => _or(ch1, ch2) }.mkString
		case ALUControl(UIntString("110"), _, _, _, _) => (src1 zip src2).map{ case (ch1, ch2) => _and(ch1, ch2) }.mkString
		case ALUControl(UIntString("111"), _, _, _, compare_flip) => if (compare_flip) Utility.binstring32(true.compare(src1 == src2), signed = false) else Utility.binstring32(true.compare(src1 != src2), signed = false)
		case _ => throw new MatchError(s"Unhandled ALUControl: $alu_control")
	}
}
