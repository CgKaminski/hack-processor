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

  logic [15:0] a_register;
  logic [15:0] d_register;
  logic [15:0] aluOut;
  logic zr, ng, po, lezr, eqzr, gtzr, jump, a_load;
  logic do_jump;
  logic [15:0] a_instruction, aluA;

  alu alu_init (
    .x(d_register),
    .y(aluA),
    .zx(instruction[11]),
    .nx(instruction[10]),
    .zy(instruction[9]),
    .ny(instruction[8]),
    .f(instruction[7]),
    .no(instruction[6]),
    .out(aluOut),
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
    a_instruction = (instruction[15]) ? aluOut: instruction;

    // A-Register
    a_load = (instruction[15]) ? instruction[5]: 1'b1;
    a_register = (a_load) ? a_instruction: a_register;
    addressM = a_register[14:0];
    aluA = (instruction[12]) ? inM: a_register;
  
    // D-Register
    d_register = (instruction[4]) ? aluOut: d_register;
    // d_register = 16'b0111111111111111;
  
    // Memory output
    writeM = (instruction[3] == 1 & instruction[15] == 1);
  
    // Program counter
    po = ~zr & ~ng;
    lezr = instruction[2] & ng;
    eqzr = instruction[1] & zr;
    gtzr = instruction[0] & po;
    jump = lezr | eqzr | gtzr;
    do_jump = jump & instruction[15];
    
    // Alu
    outM <= aluOut;

    $display("aluOut = %h", aluOut);
    $display("instruction[4] = %h", instruction[4]);
    $display("a_register = %h", a_register);
    $display("d_register = %h", d_register);
    $display("outM = %h", outM);
    $display("writeM = %h", writeM);
    $display("aluA = %h", aluA);

    end

  endmodule

