package utility

import chisel3._ 
import chisel3.util._ 


class WriteBundle (addr_width: Int = 32, data_width: Int = 32) extends Bundle {
    val write_addr: UInt = UInt(addr_width.W)
    val write_data: UInt = UInt(data_width.W)
}