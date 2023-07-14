verilator -Wall --cc memory/memory.sv --exe tests/memory_testbench.cpp
make -C obj_dir -f Vmemory.mk
obj_dir/Vmemory
