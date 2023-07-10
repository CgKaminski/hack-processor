verilator -Wall --cc helper-chips/mux4way16.sv --exe tests/mux4way16_testbench.cpp
make -C obj_dir -f Vmux4way16.mk
obj_dir/Vmux4way16
