#include "Vmux8way16.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vmux8way16* top = new Vmux8way16;

  // Test #1 
  // out = a
  top -> a = 0b1010101010101010;
  top -> b = 0b0000000000000000;
  top -> c = 0b0000000000000000;
  top -> d = 0b0000000000000000;
  top -> e = 0b0000000000000000;
  top -> f = 0b0000000000000000;
  top -> g = 0b0000000000000000;
  top -> h = 0b0000000000000000;
  top -> sel = 0b000;
  top -> eval();
  if (top -> out != top-> a)
  {
    std::cout << "Error: out != a" << std::endl;
    delete top;
    return 1;
  }

  // Test #2
  // out = b
  top -> a = 0b0000000000000000;
  top -> b = 0b0000000000000000;
  top -> c = 0b0000000000000000;
  top -> d = 0b0000000000000000;
  top -> e = 0b1010101010101010;
  top -> f = 0b0000000000000000;
  top -> g = 0b0000000000000000;
  top -> h = 0b0000000000000000;
  top -> sel = 0b100;
  top -> eval();
  if (top -> out != top-> e)
  {
    std::cout << "Error: out != e" << std::endl;
    delete top;
    return 1;
  }

  delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

