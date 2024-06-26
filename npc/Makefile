BUILD_DIR = ./build
SIM = obj_dir/VTop
SIM_AGRS += -i $(IMAGE).bin

export PATH := $(PATH):$(abspath ./utils)

verilog:
	$(call git_commit, "generate verilog")
	sbt "run top.TopDriver"
	head -n -2 vsrc/Top.sv > temp && mv temp vsrc/Top.sv

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@cd $(NPC_HOME)
	@verilator --cc --exe --build   --trace -j 0 csrc/main.cpp vsrc/Top.sv

run:
	@cd $(NPC_HOME)
	@$(SIM) $(SIM_AGRS)


-include ../Makefile
