verilator -Wall --cc helper-chips/mux8way16.sv --exe tests/mux8way16_testbench.cpp
make -C obj_dir -f Vmux8way16.mk
obj_dir/Vmux8way16
