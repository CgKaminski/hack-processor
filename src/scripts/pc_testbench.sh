verilator -Wall --cc cpu/pc.sv --exe tests/pc_testbench.cpp
make -C obj_dir -f Vpc.mk
obj_dir/Vpc
