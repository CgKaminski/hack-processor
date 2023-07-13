#include "Valu.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Valu* top = new Valu;

    // Test #1: 0
    top -> x = 0b1010010001000101;  // Binary value for x
    top -> y = 0b1100010110001010;  // Binary value for y
    top -> zx = 1;
    top -> nx = 0;
    top -> zy = 1;
    top -> ny = 0;
    top -> f = 1;
    top -> no = 0;
    top -> eval();
    if (top -> out != 0b0000000000000000 || top -> zr != 1 || top -> ng != 0) {
        std::cout << "Error in Test #1" << std::endl;
        delete top;
        return 1;
    }

    // Test #2: 1
    top -> x = 0b0110000000000101;  // Binary value for x
    top -> y = 0b0010000000001010;  // Binary value for y
    top -> zx = 1;
    top -> nx = 1;
    top -> zy = 1;
    top -> ny = 1;
    top -> f = 1;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b0000000000000001 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #2" << std::endl;
        delete top;
        return 1;
    }

    // Test #3: -1
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000000;  // Binary value for y
    top -> zx = 1;
    top -> nx = 1;
    top -> zy = 1;
    top -> ny = 0;
    top -> f = 1;
    top -> no = 0;
    top -> eval();
    if (top -> out != 0b1111111111111111 || top -> zr != 0 || top -> ng != 1) {
        std::cout << "Error in Test #3" << std::endl;
        delete top;
        return 1;
    }

    // Test #4: x
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000000;  // Binary value for y
    top -> zx = 0;
    top -> nx = 0;
    top -> zy = 1;
    top -> ny = 1;
    top -> f = 0;
    top -> no = 0;
    top->eval();
    if (top->out != 0b0000000000000101 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #4" << std::endl;
        delete top;
        return 1;
    }

    // Test #5: y
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0100101001010100;  // Binary value for y
    top -> zx = 1;
    top -> nx = 1;
    top -> zy = 0;
    top -> ny = 0;
    top -> f = 0;
    top -> no = 0;
    top -> eval();
    if (top -> out != 0b0100101001010100 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #5" << std::endl;
        delete top;
        return 1;
    }

    // Test #6: !x
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000000;  // Binary value for y
    top -> zx = 0;
    top -> nx = 0;
    top -> zy = 1;
    top -> ny = 1;
    top -> f = 0;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b1111111111111010 || top -> zr != 0 || top -> ng != 1) {
        std::cout << "Error in Test #6" << std::endl;
        delete top;
        return 1;
    }

    // Test #7: !y
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000101;  // Binary value for y
    top -> zx = 1;
    top -> nx = 1;
    top -> zy = 0;
    top -> ny = 0;
    top -> f = 0;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b1111111111111010 || top -> zr != 0 || top -> ng != 1) {
        std::cout << "Error in Test #7" << std::endl;
        delete top;
        return 1;
    }

    // Test #8: -x
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000000;  // Binary value for y 
    top -> zx = 0;
    top -> nx = 0;
    top -> zy = 1;
    top -> ny = 1;
    top -> f = 1;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b1111111111111011 || top -> zr != 0 || top -> ng != 1) {
        std::cout << "Error in Test #8" << std::endl;
        delete top;
        return 1;
    }

    // Test #9: -y
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000011;  // Binary value for y
    top -> zx = 1;
    top -> nx = 1;
    top -> zy = 0;
    top -> ny = 0;
    top -> f = 1;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b1111111111111101 || top -> zr != 0 || top -> ng != 1) {
        std::cout << "Error in Test #9" << std::endl;
        delete top;
        return 1;
    }

    // Test #10: x + 1
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000000;  // Binary value for y
    top -> zx = 0;
    top -> nx = 1;
    top -> zy = 1;
    top -> ny = 1;
    top -> f = 1;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b0000000000000110 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #10" << std::endl;
        delete top;
        return 1;
    }

    // Test #11: y + 1
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000001;  // Binary value for y
    top -> zx = 1;
    top -> nx = 1;
    top -> zy = 0;
    top -> ny = 1;
    top -> f = 1;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b0000000000000010 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #11" << std::endl;
        delete top;
        return 1;
    }

    // Test #12: x - 1
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000000;  // Binary value for y
    top -> zx = 0;
    top -> nx = 0;
    top -> zy = 1;
    top -> ny = 1;
    top -> f = 1;
    top -> no = 0;
    top -> eval();
    if (top -> out != 0b0000000000000100 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #12" << std::endl;
        delete top;
        return 1;
    }

    // Test #13: y - 1
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000101;  // Binary value for y
    top -> zx = 1;
    top -> nx = 1;
    top -> zy = 0;
    top -> ny = 0;
    top -> f = 1;
    top -> no = 0;
    top -> eval();
    if (top -> out != 0b0000000000000100 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #13" << std::endl;
        delete top;
        return 1;
    }

    // Test #14: x + y
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000011;  // Binary value for y
    top -> zx = 0;
    top -> nx = 0;
    top -> zy = 0;
    top -> ny = 0;
    top -> f = 1;
    top -> no = 0;
    top -> eval();
    if (top -> out != 0b0000000000001000 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #14" << std::endl;
        delete top;
        return 1;
    }

    // Test #15: x - y
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000111;  // Binary value for y
    top -> zx = 0;
    top -> nx = 1;
    top -> zy = 0;
    top -> ny = 0;
    top -> f = 1;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b1111111111111110 || top -> zr != 0 || top -> ng != 1) {
        std::cout << "Error in Test #15" << std::endl;
        delete top;
        return 1;
    }

    // Test #16: y - x
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000111;  // Binary value for y
    top -> zx = 0;
    top -> nx = 0;
    top -> zy = 0;
    top -> ny = 1;
    top -> f = 1;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b0000000000000010 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #16" << std::endl;
        delete top;
        return 1;
    }

    // Test #17: x & y
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000111;  // Binary value for y
    top -> zx = 0;
    top -> nx = 0;
    top -> zy = 0;
    top -> ny = 0;
    top -> f = 0;
    top -> no = 0;
    top -> eval();
    if (top -> out != 0b0000000000000101 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #17" << std::endl;
        delete top;
        return 1;
    }

    // Test #18: x | y
    top -> x = 0b0000000000000101;  // Binary value for x
    top -> y = 0b0000000000000111;  // Binary value for y
    top -> zx = 0;
    top -> nx = 1;
    top -> zy = 0;
    top -> ny = 1;
    top -> f = 0;
    top -> no = 1;
    top -> eval();
    if (top -> out != 0b0000000000000111 || top -> zr != 0 || top -> ng != 0) {
        std::cout << "Error in Test #18" << std::endl;
        delete top;
        return 1;
    }

    delete top;
    std::cout << "All tests passed successfully" << std::endl;
    return 0;
}

