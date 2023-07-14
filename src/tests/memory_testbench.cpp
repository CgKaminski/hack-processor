#include "Vmemory.h" 
#include "verilated.h"
#include <iostream> 


int main(int argc, char** argv) 
{
  Verilated::commandArgs(argc, argv);
  Vmemory* top = new Vmemory;

  // Initialize inputs
  top -> clk = 0;
  top -> load = 0;
  top -> address = 0b0000000000000000;
  top -> in = 0b0000000000000000;
  top -> eval();

  // Test 1: load @1 with 0b0000000000000001
  top -> clk = !top -> clk;
  top -> load = 0b000000000000001;
  top -> address = 0b000000000000001;
  top -> in = 0b0000000000000001;
  top -> eval();
  std::cout << "out: " << top -> out << std::endl;
  if (top -> out != 0b0000000000000001) 
  {
    std::cout << "Test 1 failed" << std::endl;
    return 1;
  }

  // Test 1.2 (should fail): load @1 with 0b0000000000000000
  top -> clk = !top -> clk;
  top -> load = 1;
  top -> address = 0b000000000000001;
  top -> in = 0b0000000000000000;
  top -> eval();
  if (top -> out != 0b0000000000000001) 
  {
    std::cout << "Test 1.2 failed" << std::endl;
    return 1;
  }

  // Test 2: load @2 with 0b0000000000000010
  top -> clk = !top -> clk;
  top -> load = 1;
  top -> address = 0b000000000000010;
  top -> in = 0b0000000000000010;
  top -> eval();
  if (top -> out != 0b0000000000000010) 
  {
    std::cout << "Test 2 failed" << std::endl;
    return 1;
  }

  // Test 2.2 (should fail): load @2 with 0b0000000000000000
  top -> clk = !top -> clk;
  top -> load = 1;
  top -> address = 0b000000000000010;
  top -> in = 0b0000000000000000;
  top -> eval();
  if (top -> out != 0b0000000000000010) 
  {
    std::cout << "Test 2.2 failed" << std::endl;
    return 1;
  }

  // Test 3: load @32767 with 0b1111111111111111
  top -> clk = !top -> clk;
  top -> load = 1;
  top -> address = 0b111111111111111;
  top -> in = 0b1111111111111111;
  top -> eval();
  if (top -> out != 0b1111111111111111) 
  {
    std::cout << "Test 3 failed" << std::endl;
    return 1;
  }

  // Test 3.2 (should fail): load @32767 with 0b0000000000000000
  top -> clk = !top -> clk;
  top -> load = 1;
  top -> address = 0b111111111111111;
  top -> in = 0b0000000000000000;
  top -> eval();
  if (top -> out != 0b1111111111111111) 
  {
    std::cout << "Test 3.2 failed" << std::endl;
    return 1;
  }

  // Test 4 read @1
  top -> clk = !top -> clk;
  top -> load = 0;
  top -> address = 0b000000000000001;
  top -> in = 0b0000000000000000;
  top -> eval();
  if (top -> out != 0b0000000000000001) 
  {
    std::cout << "Test 4 failed" << std::endl;
    return 1;
  }
  
  // Test 4.2 (should fail): read @1
  top -> clk = !top -> clk;
  top -> load = 0;
  top -> address = 0b000000000000001;
  top -> in = 0b0000000000000000;
  top -> eval();
  if (top -> out != 0b0000000000000001) 
  {
    std::cout << "Test 4.2 failed" << std::endl;
    return 1;
  }

  // Test 5 read @32767
  top -> clk = !top -> clk;
  top -> load = 0;
  top -> address = 0b0111111111111111;
  top -> in = 0b0000000000000000;
  top -> eval();
  if (top -> out != 0b1111111111111111) 
  {
    std::cout << "Test 5 failed" << std::endl;
    return 1;
  }

    delete top;
  std::cout << "Success" << std::endl;
  return 0;
}

