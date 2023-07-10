verilator -Wall --cc helper-chips/mux16.sv --exe tests/mux16_testbench.cpp
make -C obj_dir -f Vmux16.mk
obj_dir/Vmux16
