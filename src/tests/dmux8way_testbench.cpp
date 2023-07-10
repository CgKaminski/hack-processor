#include "Vdmux8way.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vdmux8way* top = new Vdmux8way;

  // Test #1 
  // in = 1, sel = 000
  // a = 1, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0
  top -> in = 1;
  top -> sel = 0b000;
  top -> eval();
  if (top -> a != 1 || top -> b != 0 || top -> c != 0 || top -> d != 0 || top -> e != 0 || top -> f != 0 || top -> g != 0 || top -> h != 0)
  {
    std::cout << "Error: a != 1 or b != 0 or c != 0 or d != 0 or e != 0 or f != 0 or g != 0 or h != 0" << std::endl;
    delete top;
    return 1;
  }

  // Test #2
  // in = 1, sel = 110
  // a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 1, h = 0
  top -> in = 1;
  top -> sel = 0b110;
  top -> eval();
  if (top -> a != 0 || top -> b != 0 || top -> c != 0 || top -> d != 0 || top -> e != 0 || top -> f != 0 || top -> g != 1 || top -> h != 0)
  {
    std::cout << "Error: a != 0 or b != 0 or c != 0 or d != 0 or e != 0 or f != 0 or g != 1 or h != 0" << std::endl;
    delete top;
    return 1;
  }

  delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

