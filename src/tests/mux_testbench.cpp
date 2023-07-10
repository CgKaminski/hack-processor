#include "Vmux.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vmux* top = new Vmux;

  // Test #1 
  // a = 1, b = 0, sel = 0
  top -> a = 1;
  top -> b = 0;
  top -> sel = 0;
  top -> eval();
  if (top -> out != 1)
  {
    std::cout << "Error: out != 1" << std::endl;
    delete top;
    return 1;
  }

  // Test #2
  // a = 1, b = 0, sel = 1
  top -> a = 1;
  top -> b = 0;
  top -> sel = 1;
  top -> eval();
  if (top -> out != 0)
  {
    std::cout << "Error: out != 0" << std::endl;
    delete top;
    return 1;
  }

  delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

