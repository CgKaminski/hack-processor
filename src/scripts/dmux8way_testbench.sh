verilator -Wall --cc helper-chips/dmux8way.sv --exe tests/dmux8way_testbench.cpp
make -C obj_dir -f Vdmux8way.mk
obj_dir/Vdmux8way
