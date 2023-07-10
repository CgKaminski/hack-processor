verilator -Wall --cc helper-chips/dmux.sv --exe tests/dmux_testbench.cpp
make -C obj_dir -f Vdmux.mk
obj_dir/Vdmux
