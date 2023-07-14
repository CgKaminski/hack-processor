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

    // Test #1: Load @12345
    top -> clk = !top -> clk;
    top -> instruction = 0b0011000000111001;
    top -> reset = 0
    top -> inM = 0b0000000000000000;
    top -> eval();
    if (top -> outM != 0 || writeM != 0 || addressM != 12345 || pc != 1) 
    {
      std::cout << "Test #1 failed" << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #2: D = A
    top -> clk = !top -> clk;
    top -> instruction = 0b1110110000010000;
    top -> reset = 0
    top -> inM = 0b0000000000000000;
    top -> eval();
    if (top -> outM != 12345 || writeM != 0 || addressM != 12345 || pc != 2) 
    {
      std::cout << "Test #2 failed" << std::endl;
      return 1;
    }


    delete top;
    std::cout << "All tests passed successfully" << std::endl;
    return 0;
}

