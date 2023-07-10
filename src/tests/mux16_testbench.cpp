#include "Vmux16.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vmux16* top = new Vmux16;

  // Test #1 
  // a = 1, b = 0, sel = 0
  top -> a = 0b1111111111111111;
  top -> b = 0b0000000000000000;
  top -> sel = 0;
  top -> eval();
  if (top -> out != top -> a)
  {
    std::cout << "Error: out != a" << std::endl;
    delete top;
    return 1;
  }

  // Test #2
  // a = 1, b = 0, sel = 1
  top -> a = 0b1111111111111111;
  top -> b = 0b0000000000000000;
  top -> sel = 1;
  top -> eval();
  if (top -> out != top -> b)
  {
    std::cout << "Error: out != b" << std::endl;
    delete top;
    return 1;
  }

  delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

