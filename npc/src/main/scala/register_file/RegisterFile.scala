package register_file

import chisel3._ 
import chisel3.util._ 

import utility._ 


class RegisterFile (num_reg: Int = 32, reg_addr_width: Int = 5, data_width: Int = 32) extends Module {
    val ZERO_ADDR: UInt = 0.U(reg_addr_width.W)

    val io = IO(new Bundle {
        val write_bundle: DecoupledIO[WriteBundle]      = Flipped(DecoupledIO(new WriteBundle(reg_addr_width, data_width)))
        val write: DecoupledIO[Bool]                    = Flipped(DecoupledIO(Bool()))
        val read_addr_1: DecoupledIO[UInt]              = Flipped(DecoupledIO(UInt(reg_addr_width.W)))
        val read_addr_2: DecoupledIO[UInt]              = Flipped(DecoupledIO(UInt(reg_addr_width.W)))

        val read_data_1: DecoupledIO[UInt]              = DecoupledIO(UInt(data_width.W))
        val read_data_2: DecoupledIO[UInt]              = DecoupledIO(UInt(data_width.W))
    })

    io.write_bundle.ready   := true.B
    io.write.ready          := true.B 
    io.read_addr_1.ready    := true.B
    io.read_addr_2.ready    := true.B 

    val registers: Vec[UInt] = Reg(Vec(num_reg, UInt(data_width.W)))

    registers(io.write_bundle.bits.write_addr) := Mux(io.write_bundle.valid && io.write_bundle.bits.write_addr =/= ZERO_ADDR, io.write_bundle.bits.write_data, registers(io.write_bundle.bits.write_addr))

    io.read_data_1.bits   := registers(io.read_addr_1.bits)
    io.read_data_1.valid  := io.read_addr_1.valid && io.read_data_1.ready

    io.read_data_2.bits   := registers(io.read_addr_2.bits)
    io.read_data_2.valid  := io.read_addr_2.valid && io.read_data_2.ready


    def peek_registers(): Unit = {
        printf(cf"Peeking registers value.\n")
        for (i <- 0 until num_reg) printf(cf"[Register $i] has value ${registers(i).asSInt}" +  (if (i % 5 == 4) "\n" else "\t||\t"))
        printf(cf"--------------------------------------------------------------------\n")
    }

    peek_registers()
}
