#include <verilated.h>
#include <iostream>
#include "Vpc.h"

int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vpc* top = new Vpc;

    // Initialize inputs 
    top -> in = 0b0000000000000000;
    top -> load = 0;
    // top -> inc = 0;
    top -> reset = 0;
    top -> clk = 0;

    // Toggle clk and eval the module
    for (int i = 0; i < 4; ++i)
    {

      // Test #1 
      // in = 1, load = 1, inc = 0, reset = 0
      // out = 1
      top -> clk = !top -> clk;
      top -> in = 0b0000000000000000 + i;
      top -> load = 1;
      // top -> inc = 0;
      top -> reset = 0;
      top -> eval();
      std::cout << "i: " << i << ", out: " << top -> out << std::endl;
      if ((top -> out != i && top -> clk) || 
        (top -> out != i - 1 && !top -> clk))       
      {
        std::cout << "Error: at index i: " << i << std::endl;
        delete top;
        return 1;
      }
    }

    // Test #2
    // in = 0, load = 0, inc = 0, reset = 1, clk = 1
    // out = 2
    top -> clk = !top -> clk;
    top -> in = 0b0111010110101111;
    top -> load = 0;
    // top -> inc = 0;
    top -> reset = 1;
    top -> eval();
    std::cout << "out: " << top -> out << std::endl;
    if (top -> out != 0b0000000000000000) 
    {
        std::cout << "Test 2 Error: out is not equal to 0" << std::endl;
        delete top;
        return 1;
    }

    // Test #3
    // in = 0, load = 1, inc = 0, reset = 0, clk = 0
    // out = 0
    top -> clk = !top -> clk;
    top -> in = 0b0000000000000011;
    top -> load = 1; 
    // top -> inc = 0;
    top -> reset = 0;
    top -> eval();
    std::cout << "out: " << top -> out << std::endl;
    if (top->out != 0)
    {
        std::cout << "Test 3 Error: out is not equal to 3" << std::endl;
        delete top;
        return 1;
    }

    // Test #4
    // in = 0, load = 0, inc = 1, reset = 0, clk = 1
    // out = 0
    top -> clk = !top -> clk;
    top -> in = 0b0000111111111111;
    top -> load = 0;
    // top -> inc = 1;
    top -> reset = 0;
    top -> eval();
    std::cout << "out: " << top -> out << std::endl;
    if (top->out != 1)
    {
        std::cout << "Test 4 Error: out is not equal to 3" << std::endl;
        delete top;
        return 1;
    }



    // Test #5
    // in = 0, load = 0, inc = 1, reset = 0, clk = 0
    // out = 0
    top -> clk = !top -> clk;
    top -> in = 0b0000000000000011;
    top -> load = 1;
    // top -> inc = 0;
    top -> reset = 0;
    top -> eval();
    std::cout << "out: " << top -> out << std::endl;
    if (top->out != 1)
    {
        std::cout << "Test 5 Error: out is not equal to 1" << std::endl;
        delete top;
        return 1;
    }
    
    // Test #6
    // in = 0, load = 0, inc = 1, reset = 0, clk = 1
    // out = 0
    top -> clk = !top -> clk;
    top -> in = 0b0000000000000011;
    top -> load = 1;
    // top -> inc = 0;
    top -> reset = 0;
    top -> eval();
    std::cout << "out: " << top -> out << std::endl;
    if (top->out != 3)
    {
        std::cout << "Test 6 Error: out is not equal to 1" << std::endl;
        delete top;
        return 1;
    }
    // Add more test cases as needed

    delete top;
    std::cout << "Success" << std::endl;
    return 0;
}
