/**
 * The Hack CPU (Central Processing unit), consisting of an ALU,
 * two registers named A and D, and a program counter named PC.
 * The CPU is designed to fetch and execute instructions written in 
 * the Hack machine language. In particular, functions as follows:
 * Executes the inputted instruction according to the Hack machine 
 * language specification. The D and A in the language specification
 * refer to CPU-resident registers, while M refers to the external
 * memory location addressed by A, i.e. to Memory[A]. The inM input 
 * holds the value of this location. If the current instruction needs 
 * to write a value to M, the value is placed in outM, the address 
 * of the target location is placed in the addressM output, and the 
 * writeM control bit is asserted. (When writeM==0, any value may 
 * appear in outM). The outM and writeM outputs are combinational: 
 * they are affected instantaneously by the execution of the current 
 * instruction. The addressM and pc outputs are clocked: although they 
 * are affected by the execution of the current instruction, they commit 
 * to their new values only in the next time step. If reset==1 then the 
 * CPU jumps to address 0 (i.e. pc is set to 0 in next time step) rather 
 * than to the address resulting from executing the current instruction. 
 */

module cpu(input logic [15:0] inM, instruction,
           input logic reset,
           output logic [15:0] outM,
           output logic [14:0] addressM, pc,
           output logic writeM);

  // CPU instruction decoding
  // if (instruction[15] == 0) then A-instruction
  // else C-instruction
  assign a_instruction = (instruction[15] == 1) ? aluOut: instruction;

  // A-Register
  assign a_load = (instruction[15] == 0) ? 1'b1: 1'b0;
  ARegister #(16) a_register(.in(a_instruction), .load(a_load), .out(a_out));
  assign aluA = (instruction[12] == 0) ? a_out: inM;

  // D-Register
  DRegister #(16) d_register(.in(aluOut), .load(instruction[4]), .out(d_out));

  // ALU and output 
  ALU alu(.x(aluA), .y(d_out), .zx(instruction[11]), .nx(instruction[10]), 
          .zy(instruction[9]), .ny(instruction[8]), .f(instruction[7]), 
          .no(instruction[6]), .out(aluOut), .zr(zr), .ng(ng));

  // Memory output
  assign writeM = (instruction[3] ==1 && instruction[15] == 1);

  // Program counter
  assign po = ~zr & ~ng;
  // Jump condition
  assign lezr = instruction[2] & ng;
  assign eqzr = instruction[1] & zr;
  assign gtzr = instruction[0] & po;
  assign jump = lezr | eqzr | gtzr;
  assign do_jump = jmp & instruction[15];
  PC #(15) pc(.in(a_out), .load(do_jump), .inc(~do_jump), .reset(reset), 
              .out(pc));

  endmodule

