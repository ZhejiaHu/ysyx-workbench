package utility
import scala.language.implicitConversions

import chisel3._ 
import chisel3.util._ 


class UIntString[N <: Int] private (val value: String) extends Iterable[Char] {
	val len = value.length		
	override def toString: String = s"UIntString($value)"	
	def apply(index: Int): Char = value.charAt(len - 1 - index)	
	def slice[K <: Int : ValueOf](from: Int, until: Int): UIntString[K] = new UIntString[K](value.slice(len - 1 - from, len - until))	
	def U(len: Int): UInt = ("b" + value).U(len.W)	
	def toInt(signed: Boolean): BigInt = (value.substring(1).toList zip (len - 2 to 0 by -1).toList).foldLeft((if (signed) -1 else 1) * BigInt(value(0).asDigit) * (BigInt(1) << (len - 1))){case (acc, (cur, p)) => acc + BigInt(cur.asDigit) * (BigInt(1) << p)}	
	def <<(n: Int): UIntString[N] = new UIntString[N](value.substring(n) + "0" * n)	
	def >>(n: Int): UIntString[N] = new UIntString[N]("0" * n + value.slice(0, len - n))	
	def >>>(n: Int): UIntString[N] = new UIntString[N](value.charAt(0).toString * n + value.slice(0, len - n))

	override def iterator: Iterator[Char] = new Iterator[Char] {
		private var it = -1
		override def hasNext: Boolean = it < len - 1
		override def next(): Char = {
			it += 1
			value.charAt(it)
		}
	}

	override def equals(obj: Any): Boolean = obj match {
		case that: UIntString[_] => this.value == that.value
		case _ => false 
	}

	override def hashCode(): Int = value.hashCode
}

object UIntString {
	def apply[N <: Int : ValueOf](s: String): UIntString[N] = {
	  val length = implicitly[ValueOf[N]].value
	  if (s.length == length) new UIntString[N](s)
	  else throw new IllegalArgumentException(s"String length ${s.length} must be $length")
	}

	def unapply[N <: Int](u: UIntString[N]): Option[String] = Some(u.value)	

	implicit def stringToUIntString[N <: Int : ValueOf](s: String): UIntString[N] = apply[N](s)
}