verilator -Wall --cc helper-chips/dmux4way.sv --exe tests/dmux4way_testbench.cpp
make -C obj_dir -f Vdmux4way.mk
obj_dir/Vdmux4way
