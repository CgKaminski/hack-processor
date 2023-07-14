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

`include "alu.sv"
`include "pc.sv"

module cpu(input logic [15:0] inM, instruction,
           input logic reset, clk,
           output logic [15:0] outM, pc,
           output logic [14:0] addressM,
           output logic writeM);

  reg [15:0] a_register;
  reg [15:0] d_register;
  logic zr, ng, po, lezr, eqzr, gtzr, jump, a_load;
  logic jmp, do_jump;
  logic [15:0] a_instruction, aluA;

  alu alu_init (
    .x(aluA),
    .y(d_register),
    .zx(instruction[11]),
    .nx(instruction[10]),
    .zy(instruction[9]),
    .ny(instruction[8]),
    .f(instruction[7]),
    .no(instruction[6]),
    .out(outM),
    .zr(zr),
    .ng(ng)
  );

  pc pc_init (
    .in(a_register),
    .load(do_jump),
    .inc(~do_jump),
    .reset(reset),
    .clk(clk),
    .out(pc)
  );
  always_ff @(posedge clk) begin
    // CPU instruction decoding
    // if (instruction[15] == 0) then A-instruction
    // else C-instruction
    assign a_instruction = (instruction[15] == 1) ? outM: instruction;
  
    // A-Register
    assign a_load = (instruction[15] == 0) ? 1'b1: 1'b0;
    assign a_register = (a_load) ? a_instruction: a_register;
    addressM = a_register[14:0];
    assign aluA = (instruction[12] == 1) ? a_register: inM;
  
    // D-Register
    assign d_register = (instruction[4]) ? outM: d_register;
  
    // ALU and output 
//    ALU alu(.x(aluA), .y(d_register), .zx(instruction[11]), .nx(instruction[10]), 
//            .zy(instruction[9]), .ny(instruction[8]), .f(instruction[7]), 
//            .no(instruction[6]), .out(aluOut), .zr(zr), .ng(ng));
  
    // Memory output
    assign writeM = (instruction[3] ==1 && instruction[15] == 1);
  
    // Program counter
    assign po = ~zr & ~ng;
    assign lezr = instruction[2] & ng;
    assign eqzr = instruction[1] & zr;
    assign gtzr = instruction[0] & po;
    assign jump = lezr | eqzr | gtzr;
    assign do_jump = jmp & instruction[15];
//    PC pc(.in(a_register), .load(do_jump), .inc(~do_jump), .reset(reset), 
//          .clk(clk), .out(pc));

    end

  endmodule

