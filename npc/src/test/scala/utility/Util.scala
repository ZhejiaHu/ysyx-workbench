package utility

import scala.util.Random


object Utility {
	def random_binstring(width: Int): String = {
		val random = new Random
		(1 to width).map(_ => if (random.nextBoolean()) '1' else '0').mkString
	}

	def binstring32(num: Int, signed: Boolean): UIntString[32] = {
		if (num < 0 && !signed) throw new Exception(s"[Utility] Unsigned number could not be negative ($num < 0 and signed is $signed)")
		if (num < 0) return num.toBinaryString
		val binstr = num.toBinaryString
		return "0" * (32 - binstr.length()) + binstr 
	}
}
