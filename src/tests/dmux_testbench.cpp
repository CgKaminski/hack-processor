#include "Vdmux.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vdmux* top = new Vdmux;

  // Test #1 
  // in = 1, sel = 0
  // a = 1, b = 0
  top -> in = 1;
  top -> sel = 0;
  top -> eval();
  if (top -> a != 1 || top -> b != 0)
  {
    std::cout << "Error: a != 1 or b != 0" << std::endl;
    delete top;
    return 1;
  }

  // Test #2
  // in = 1, sel = 1
  // a = 0, b = 1
  top -> in = 1;
  top -> sel = 1;
  top -> eval();
  if (top -> a != 0 || top -> b != 1)
  {
    std::cout << "Error: a != 0 or b != 0" << std::endl;
    delete top;
    return 1;
  }

  // Test #3
  // in = 0, sel = 0
  // a = 0, b = 0
  top -> in = 0;
  top -> sel = 0;
  top -> eval();
  if (top -> a != 0 || top -> b != 0)
  {
    std::cout << "Error: a != 0 or b != 0" << std::endl;
    delete top;
    return 1;
  }

  delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

