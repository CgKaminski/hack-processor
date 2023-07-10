#include "Vmux4way16.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vmux4way16* top = new Vmux4way16;

  // Test #1 
  // out = a
  top -> a = 0b1010101010101010;
  top -> b = 0b0000000000000000;
  top -> c = 0b0000000000000000;
  top -> d = 0b0000000000000000;
  top -> sel = 0b00;
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
  top -> b = 0b1010101010101010;
  top -> c = 0b0000000000000000;
  top -> d = 0b0000000000000000;
  top -> sel = 0b01;
  top -> eval();
  if (top -> out != top-> b)
  {
    std::cout << "Error: out != b" << std::endl;
    delete top;
    return 1;
  }

  // Test #3
  // out = c
  top -> a = 0b0000000000000000;
  top -> b = 0b0000000000000000;
  top -> c = 0b1010101010101010;
  top -> d = 0b0000000000000000;
  top -> sel = 0b10;
  top -> eval();
  if (top -> out != top-> c)
  {
    std::cout << "Error: out != c" << std::endl;
    delete top;
    return 1;
  }

  // Test #4
  // out = d
  top -> a = 0b0000000000000000;
  top -> b = 0b0000000000000000;
  top -> c = 0b0000000000000000;
  top -> d = 0b1010101010101010;
  top -> sel = 0b11;
  top -> eval();
  if (top -> out != top-> d)
  {
    std::cout << "Error: out != d" << std::endl;
    delete top;
    return 1;
  }

  delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

