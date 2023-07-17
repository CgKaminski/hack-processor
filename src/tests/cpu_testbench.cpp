#include "Vcpu.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vcpu* top = new Vcpu;


    // Initialize inputs for cpu
    top -> clk = 0;
    top -> inM = 0b0000000000000000;
    top -> reset = 1;
    top -> instruction = 0b0000000000000000;
    top -> eval();

    // Test #1: Load @12345
    std::cout << "Test #1 Load @12345" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x3039;
    top -> reset = 0;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x3039 || top -> dRegister != 0x0 || top -> pc != 1
        || top -> outM != 0 || top -> addressM != 0x3039)
    {
      std::cout << "Test #1 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #2: D = A
    std::cout << "Test #2 D = A" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xec10;
    top -> reset = 0;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x3039 || top -> dRegister != 0x3039 
        || top -> pc != 2 || top -> outM != 0x3039 || top -> addressM != 0x3039)
    {
      std::cout << "Test #2 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #3: @23456
    std::cout << "Test #3 @23456" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x5ba0;
    top -> reset = 0;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x5ba0 || top -> dRegister != 0x3039 
        || top -> pc != 3 || top -> outM != 0xffff || top -> addressM != 0x5ba0)
    {
      std::cout << "Test #3 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #4: AD = A - D
    std::cout << "Test #4 AD = A - D" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe1f0;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x2b67 || top -> dRegister != 0x2b67 
        || top -> pc != 4 || top -> outM != 0x0000 || top -> addressM != 0x2b67)
    {
      std::cout << "Test #4 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }
    
    top -> clk = !top -> clk;
    top -> eval();

    // Test #5: @1003
    std::cout << "Test #5 @1003" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x03eb;
    top -> reset = 0b0;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03eb|| top -> dRegister != 0x2b67 
        || top -> pc != 5 || top -> outM != 0xd499|| top -> addressM != 0x03eb)
    {
      std::cout << "Test #5 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #6: M=D
    std::cout << "Test #6 M=D" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe308;
    top -> reset = 0x000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03eb|| top -> dRegister != 0x2b67
        || top -> pc != 6 || top -> outM != 0x2b67 || top -> addressM != 0x03eb)
    {
      std::cout << "Test #6 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #7: @1004
    std::cout << "Test #7 @1004" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x03ec;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03ec|| top -> dRegister != 0x2b67 
        || top -> pc != 7 || top -> outM != 0xd499 || top -> addressM != 0x03ec)
    {
      std::cout << "Test #7 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #8: MD=D-1
    std::cout << "Test #8 MD=D-1" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe398;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03ec|| top -> dRegister != 0x2b66
        || top -> pc != 8 || top -> outM != 0x2b65 || top -> addressM != 0x03ec)
    {
      std::cout << "Test #8 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #9: @1000
    std::cout << "Test #9 @1000" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x03e8;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03e8|| top -> dRegister != 0x2b66 
        || top -> pc != 9 || top -> outM != 0xd49a || top -> addressM != 0x03e8)
    {
      std::cout << "Test #9 failed" << std::endl;
      std::cout << "outM: " << top -> outM << std::endl;
      std::cout << "writeM: " << top -> writeM << std::endl;
      std::cout << "addressM: " << top -> addressM << std::endl;
      std::cout << "pc: " << top -> pc << std::endl;
      std::cout << "A: " << top -> aRegister << std::endl;
      std::cout << "D: " << top -> dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #10: AD=D-M
    // inM = 11111
    std::cout << "Test #10 AD=D-M" << std::endl;
    top -> clk = !top -> clk;
    // top -> instruction = 0xf4f0;
    top -> instruction = 0xf4f0;
    top -> reset = 0x0000;
    top -> inM = 0x2b67;
    top -> eval();
    if (top -> aRegister != 0xffff || top -> dRegister != 0xffff
        || top -> pc != 0x000a || top -> outM != 0xd498
        || top -> addressM != 0x7fff)
    {
      std::cout << "Test #10 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #11: @14
    std::cout << "Test #11 @14" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x000e;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x000e || top -> dRegister != 0xffff 
        || top -> pc != 0x000b || top -> outM != 0x000e
        || top -> addressM != 0x000e)
    {
      std::cout << "Test #11 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #12: D;jlt
    std::cout << "Test #12 D;jlt" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe304;
    top -> inM = 0x0000;
    top -> reset = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x000e || top -> dRegister != 0xffff 
        || top -> pc != 0x000e || top -> outM != 0xffff
        || top -> addressM != 0x000e)
    {
      std::cout << "Test #12 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;      
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #13: @999
    std::cout << "Test #13 @999" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x03e7;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03e7 || top -> dRegister != 0xffff 
        || top -> pc != 0x000f || top -> outM != 0x0001
        || top -> addressM != 0x03e7)
    {
      std::cout << "Test #13 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;      
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #14: A = M + 1
    // inM = 11111
    std::cout << "Test #14 A = M + 1" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xfde0;
    top -> reset = 0x0000;
    top -> inM = 0x2b67;
    top -> eval();
    if (top -> aRegister != 0x2b68 || top -> dRegister != 0xffff
        || top -> pc != 0x0010 || top -> outM != 0x2b68
        || top -> addressM != 0x2b68)
    {
      std::cout << "Test #14 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #15: A M = D
    std::cout << "Test #15 A M = D" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe328;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0xffff || top -> dRegister != 0xffff
        || top -> pc != 0x0011 || top -> outM != 0xffff
        || top -> addressM != 0x7fff)
    {
      std::cout << "Test #15 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #16: @21
    std::cout << "Test #16 @21" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x015;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x0015 || top -> dRegister != 0xffff
        || top -> pc != 0x0012 || top -> outM != 0x0015
        || top -> addressM != 0x0015)
    {
      std::cout << "Test #16 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #17: D + 1;jeq
    std::cout << "Test #17 D + 1;jeq" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe7c2;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x0015 || top -> dRegister != 0xffff
        || top -> pc != 0x0015 || top -> outM != 0x0000
        || top -> addressM != 0x0015)
    {
      std::cout << "Test #17 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #18: @2
    std::cout << "Test #18 @2" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x002;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x0002 || top -> dRegister != 0xffff
        || top -> pc != 0x0016 || top -> outM != 0x0002
        || top -> addressM != 0x0002)
    {
      std::cout << "Test #18 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();
    
    // Test #19: AMD = D + A
    std::cout << "Test #19 AMD = D + A" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe0b8;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x0001 || top -> dRegister != 0x0001
        || top -> pc != 0x0017 || top -> outM != 0x0002
        || top -> addressM != 0x0001)
    {
      std::cout << "Test #19 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #20: M = M + 1
    // inM = 11111
    std::cout << "Test #20 M = M + 1" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xfdc8;
    top -> reset = 0x0000;
    top -> inM = 0x2b67;
    top -> eval();
    if (top -> aRegister != 0x0001 || top -> dRegister != 0x0001
        || top -> pc != 0x0018 || top -> outM != 0x2b68
        || top -> addressM != 0x0001)
    {
      std::cout << "Test #20 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #21: AM = M - 1
    // inM = 11111
    std::cout << "Test #21 AM = M - 1" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xfca8;
    top -> reset = 0x0000;
    top -> inM = 0x2b67;
    top -> eval();
    if (top -> aRegister != 0x2b66 || top -> dRegister != 0x0001
        || top -> pc != 0x0019 || top -> outM != 0x2b66
        || top -> addressM != 0x2b66)
    {
      std::cout << "Test #21 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #22: @1000
    std::cout << "Test #22 @1000" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0x03e8;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03e8 || top -> dRegister != 0x0001
        || top -> pc != 0x001a || top -> outM != 0xffff
        || top -> addressM != 0x03e8)
    {
      std::cout << "Test #22 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #23: D = -1
    std::cout << "Test #23 D = -1" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xee90;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03e8 || top -> dRegister != 0xffff
        || top -> pc != 0x001b || top -> outM != 0xffff
        || top -> addressM != 0x03e8)
    {
      std::cout << "Test #23 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    top -> clk = !top -> clk;
    top -> eval();

    // Test #24: D;JGT
    std::cout << "Test #24 D;JGT" << std::endl;
    top -> clk = !top -> clk;
    top -> instruction = 0xe301;
    top -> reset = 0x0000;
    top -> inM = 0x0000;
    top -> eval();
    if (top -> aRegister != 0x03e8 || top -> dRegister != 0xffff
        || top -> pc != 0x001c || top -> outM != 0xffff
        || top -> addressM != 0x03e8)
    {
      std::cout << "Test #24 failed" << std::endl;
      std::cout << "outM: " << std::hex << top->outM << std::endl;
      std::cout << "writeM: " << std::hex << top->writeM << std::endl;
      std::cout << "addressM: " << std::hex << top->addressM << std::endl;
      std::cout << "pc: " << std::hex << top->pc << std::endl;
      std::cout << "A: " << std::hex << top->aRegister << std::endl;
      std::cout << "D: " << std::hex << top->dRegister << std::endl;
      return 1;
    }

    delete top;
    std::cout << "All tests passed successfully" << std::endl;
    return 0;
}

