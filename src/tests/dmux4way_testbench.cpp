#include "Vdmux4way.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vdmux4way* top = new Vdmux4way;

  // Test #1 
  // in = 1, sel = 00
  // a = 1, b = 0, c = 0, d = 0
  top -> in = 1;
  top -> sel = 0b00;
  top -> eval();
  if (top -> a != 1 || top -> b != 0 || top -> c != 0 || top -> d != 0)
  {
    std::cout << "Error: a != 1 or b != 0 or c != 0 or d != 0" << std::endl;
    delete top;
    return 1;
  }

  // Test #2
  // in = 1, sel = 01
  // a = 0, b = 1, c = 0, d = 0
  top -> in = 1;
  top -> sel = 0b01;
  top -> eval();
  if (top -> a != 0 || top -> b != 1 || top -> c != 0 || top -> d != 0)
  {
    std::cout << "Error: a != 0 or b != 1 or c != 0 or d != 0" << std::endl;
    delete top;
    return 1;
  }

  // Test #3
  // in = 0, sel = 10
  // a = 0, b = 0, c = 1, d = 0
  top -> in = 1;
  top -> sel = 0b10;
  top -> eval();
  if (top -> a != 0 || top -> b != 0 || top -> c != 1 || top -> d != 0)
  {
    std::cout << "Error: a != 0 or b != 0 or c != 1 or d != 0" << std::endl;
    delete top;
    return 1;
  }

  // Test #4
  // in = 0, sel = 11
  // a = 0, b = 0, c = 0, d = 1
  top -> in = 1;
  top -> sel = 0b11;
  top -> eval();
  if (top -> a != 0 || top -> b != 0 || top -> c != 0 || top -> d != 1)
  {
    std::cout << "Error: a != 0 or b != 0 or c != 0 or d != 1" << std::endl;
    delete top;
    return 1;
  }

  delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

