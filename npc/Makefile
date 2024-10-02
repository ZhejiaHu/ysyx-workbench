BUILD_DIR = ./build
SIM = obj_dir/VTop
SIM_ARGS += -i $(IMAGE).bin -e $(IMAGE).elf -d $(NEMU_HOME)/build/riscv32-nemu-interpreter-so

export PATH := $(PATH):$(abspath ./utils)

# LLVM configuration
LLVM_CONFIG = llvm-config
LLVM_CXXFLAGS = `$(LLVM_CONFIG) --cxxflags`
LLVM_LDFLAGS = `$(LLVM_CONFIG) --ldflags`
LLVM_LIBS = `$(LLVM_CONFIG) --libs all`
LLVM_SYSLIBS = `$(LLVM_CONFIG) --system-libs`

# Verilog generation step
verilog:
	$(call git_commit, "generate verilog")
	sbt "run top.TopDriver"
	head -n -2 vsrc/Top.sv > temp && mv temp vsrc/Top.sv

# Simulation target using Verilator
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@cd $(NPC_HOME)
	@verilator --cc --exe --build --trace -j 0 \
		--CFLAGS "$(LLVM_CXXFLAGS) -std=c++17 -fexceptions" \
		--LDFLAGS "$(LLVM_LDFLAGS) $(LLVM_LIBS) $(LLVM_SYSLIBS)" \
		csrc/main.cpp vsrc/Top.sv

# Run the simulation
run:
	@cd $(NPC_HOME)
	@$(SIM) $(SIM_ARGS)

-include ../Makefile
