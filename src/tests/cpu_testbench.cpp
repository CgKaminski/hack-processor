#include "Vcpu.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vcpu* top = new Vcpu;


    // Initialize inputs for cpu
    top -> clk = 0;
    top -> inM = 0b0000000000000000;
    top -> reset = 0;
    top -> instruction = 0b0000000000000000;
    top -> eval();

    // Test #1: Load @12345
    std::cout << "Test #1 Load @12345" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0b0011000000111001;
    top -> reset = 0;
    top -> inM = 0b0000000000000000;
    top -> eval();
    if (top -> outM != 0 || top -> writeM != 0 || top -> addressM != 12345 || top -> pc != 1) 
    {
      std::cout << "Test #1 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #2: D = A
    std::cout << "Test #2 D = A" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0b1110110000010000;
    top -> reset = 0;
    top -> inM = 0b0000000000000000;
    top -> eval();
    std::cout << "outM: " << top -> outM << std::endl;
    std::cout << "writeM: " << top -> writeM << std::endl;
    std::cout << "addressM: " << top -> addressM << std::endl;
    std::cout << "pc: " << top -> pc << std::endl;
    if (top -> outM != 12345 || top -> writeM != 0 || top -> addressM != 12345 || top -> pc != 2) 
    {
      std::cout << "Test #2 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #3: @23456
    std::cout << "Test #3 @23456" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0b0101101110100000;
    top -> reset = 0;
    top -> inM = 0b0000000000000000;
    top -> eval();
    if (top -> outM != 0xffff || top -> writeM != 0 || top -> addressM != 0x5ba0 || top -> pc != 3) 
    {
      std::cout << "Test #3 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #4: AD = A - D
    std::cout << "Test #4 AD = A - D" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe1f0;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> outM != 0x0000 || top -> writeM != 0x0000 || top -> addressM != 0x2b67 || top -> pc != 0x004) 
    {
      std::cout << "Test #4 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      return 1;
    }




    delete top;
    std::cout << "All tests passed successfully" << std::endl;
    return 0;
}

