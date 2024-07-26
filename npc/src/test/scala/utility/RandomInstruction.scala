package utility  


object RandomInstruction {
	def random_instruction(inst_name: String): UIntString[32] = inst_name match {
		case "addi"		=> Seq(Utility.random_binstring(12), Utility.random_binstring(5), "000", Utility.random_binstring(5), "0010011").mkString
		case "slli" 	=> Seq("0000000", Utility.random_binstring(5), Utility.random_binstring(5), "001", Utility.random_binstring(5), "0010011").mkString
		case "slti" 	=> Seq(Utility.random_binstring(12), Utility.random_binstring(5), "010", Utility.random_binstring(5), "0010011").mkString
		case "sltiu" 	=> Seq(Utility.random_binstring(12), Utility.random_binstring(5), "011", Utility.random_binstring(5), "0010011").mkString
		case "srai"		=> Seq(Utility.random_binstring(12), Utility.random_binstring(5), "101", Utility.random_binstring(5), "0010011").mkString
		case "andi"		=> Seq(Utility.random_binstring(12), Utility.random_binstring(5), "111", Utility.random_binstring(5), "0010011").mkString

		case "lbu"		=> Seq(Utility.random_binstring(12), Utility.random_binstring(5), "100", Utility.random_binstring(5), "0000011").mkString	

		case "add"		=> Seq("0000000", Utility.random_binstring(5), Utility.random_binstring(5), "000", Utility.random_binstring(5), "0110011").mkString
		case "sll"		=> Seq("0000000", Utility.random_binstring(5), Utility.random_binstring(5), "001", Utility.random_binstring(5), "0110011").mkString
		case "sltu" 	=> Seq("0000000", Utility.random_binstring(5), Utility.random_binstring(5), "011", Utility.random_binstring(5), "0110011").mkString
		case "and" 		=> Seq("0000000", Utility.random_binstring(5), Utility.random_binstring(5), "111", Utility.random_binstring(5), "0110011").mkString

		case "bne"		=> Seq(Utility.random_binstring(7), Utility.random_binstring(5), Utility.random_binstring(5), "001", Utility.random_binstring(5), "1100011").mkString
		case "bge" 		=> Seq(Utility.random_binstring(7), Utility.random_binstring(5), Utility.random_binstring(5), "101", Utility.random_binstring(5), "1100011").mkString
		case "bgeu"		=> Seq(Utility.random_binstring(7), Utility.random_binstring(5), Utility.random_binstring(5), "111", Utility.random_binstring(5), "1100011").mkString 

		case "auipc" 	=> Seq(Utility.random_binstring(20), Utility.random_binstring(5), "0010111").mkString
		case "lui"		=> Seq(Utility.random_binstring(20), Utility.random_binstring(5), "0110111").mkString
	}
}
