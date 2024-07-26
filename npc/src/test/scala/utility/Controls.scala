package utility 

case class ALUControl(alu_op: UIntString[3], unsigned_src: Boolean, negate_src2: Boolean, compare: Boolean, compare_flip: Boolean) {override def toString: String = s"ALUControl(alu_op = $alu_op, unsigned_src = $unsigned_src, negate_src2 = $negate_src2, compare = $compare, compare_flip = $compare_flip)"}
case class MemoryControl(mem_op: UIntString[3], unsigned_data: Boolean) {override def toString: String = s"MemControl(mem_op = $mem_op, unsigned_data = $unsigned_data)"}
case class Control(pc_src: UIntString[2], result_src: UIntString[2], alu_src: Boolean, imm_src: UIntString[3], reg_wr: Boolean) {override def toString: String = s"Control(prc_src = $pc_src, result_src = $result_src, alu_src = $alu_src, imm_src = $imm_src, reg_wr = $reg_wr)"}

case class ControlUnitOutputs(alu_control: ALUControl, mem_control: MemoryControl, control: Control)


object ControlUnitSolution {

	def control_signals32(inst: UIntString[32]): ControlUnitOutputs = inst.slice[7](6, 0) match {
		case UIntString("0000011") => {
			val control: Control = Control(pc_src = "00", result_src = "01", alu_src = true, imm_src = "001", reg_wr = true)
			val alu_control: ALUControl = ALUControl(alu_op = "001", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
			val mem_control: MemoryControl = inst.slice[3](14, 12) match {
				case UIntString("100")	=> MemoryControl(mem_op = "001", unsigned_data = true)
			}
			ControlUnitOutputs(alu_control = alu_control, mem_control = mem_control, control = control)
		}


		case UIntString("0010011")	=> {
			val mem_control: MemoryControl = MemoryControl(mem_op = "000", unsigned_data = false)
			val control: Control = Control(pc_src = "00", result_src = "00", alu_src = true, imm_src = "001", reg_wr = true)
			val alu_control: ALUControl = inst.slice[3](14, 12) match {
				case UIntString("000") 	=> ALUControl(alu_op = "001", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
				case UIntString("001")	=> ALUControl(alu_op = "010", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
				case UIntString("010")	=> ALUControl(alu_op = "001", unsigned_src = false, negate_src2 = true, compare = true, compare_flip = false)
				case UIntString("011") 	=> ALUControl(alu_op = "001", unsigned_src = true, negate_src2 = true, compare = true, compare_flip = false)
				case UIntString("101") 	=> ALUControl(alu_op = "011", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
				case UIntString("111") 	=> ALUControl(alu_op = "110", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
			}
			ControlUnitOutputs(alu_control = alu_control, mem_control = mem_control, control = control)
		}

		case UIntString("0110011") 	=> {
			val mem_control: MemoryControl = MemoryControl(mem_op = "000", unsigned_data = false)
			val control: Control = Control(pc_src = "00", result_src = "00", alu_src = false, imm_src = "101", reg_wr = true)
			val alu_control: ALUControl = (inst.slice[7](31, 25), inst.slice[3](14, 12)) match {
				case (UIntString("0000000"), UIntString("000"))	=> ALUControl(alu_op = "001", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
				case (UIntString("0000000"), UIntString("001")) => ALUControl(alu_op = "010", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
				case (UIntString("0000000"), UIntString("011")) => ALUControl(alu_op = "001", unsigned_src = true, negate_src2 = true, compare = true, compare_flip = false)
				case (UIntString("0000000"), UIntString("111")) => ALUControl(alu_op = "110", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
			}
			ControlUnitOutputs(alu_control = alu_control, mem_control = mem_control, control = control)
		}

		case UIntString("1100011")	=> {
			val mem_control: MemoryControl = MemoryControl(mem_op = "000", unsigned_data = false)
			val control: Control = Control(pc_src = "10", result_src = "00", alu_src = false, imm_src = "010", reg_wr = false)
			val alu_control: ALUControl = inst.slice[3](14, 12) match {
				case UIntString("001")	=> ALUControl(alu_op = "111", unsigned_src = false, negate_src2 = false, compare = true, compare_flip = true)
				case UIntString("101")	=> ALUControl(alu_op = "001", unsigned_src = false, negate_src2 = true, compare = true, compare_flip = true)
				case UIntString("111")	=> ALUControl(alu_op = "001", unsigned_src = true, negate_src2 = true, compare = true, compare_flip = true)
			}
			ControlUnitOutputs(alu_control = alu_control, mem_control = mem_control, control = control)
		}

		case UIntString("0010111") => {
			val mem_control: MemoryControl = MemoryControl(mem_op = "000", unsigned_data = false)
			val control: Control = Control(pc_src = "00", result_src = "11", alu_src = true, imm_src = "111", reg_wr = true)
			val alu_control = ALUControl(alu_op = "000", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
			ControlUnitOutputs(alu_control = alu_control, mem_control = mem_control, control = control)
		}

		case UIntString("0110111") => {
			val mem_control: MemoryControl = MemoryControl(mem_op = "000", unsigned_data = false)
			val control: Control = Control(pc_src = "00", result_src = "00", alu_src = true, imm_src = "111", reg_wr = true)
			val alu_control = ALUControl(alu_op = "000", unsigned_src = false, negate_src2 = false, compare = false, compare_flip = false)
			ControlUnitOutputs(alu_control = alu_control, mem_control = mem_control, control = control)
		}
	} 
}