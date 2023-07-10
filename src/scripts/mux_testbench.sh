verilator -Wall --cc helper-chips/mux.sv --exe tests/mux_testbench.cpp
make -C obj_dir -f Vmux.mk
obj_dir/Vmux
