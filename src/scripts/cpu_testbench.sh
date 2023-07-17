verilator --cc cpu/cpu.sv +incdir+cpu --Wall -O0 --exe tests/cpu_testbench.cpp
make -C obj_dir -f Vcpu.mk
obj_dir/Vcpu
