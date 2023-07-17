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
           output reg [15:0] aRegister, dRegister,
           output logic [14:0] addressM,
           output logic writeM);

  // CPU interanl registers (denoted A and D)
  // reg [15:0] aRegister, dRegister;
  // Instruction encoding
  logic i, a, zx, nx, zy, ny, f, no;
  // Register control
  logic dA, dD, dM;
  // Jump encoding
  logic leJ, eqJ, gtJ;
  // ALU and Program counter
  logic [15:0] aluX, aluY, aluOut;
  logic zr, ng, po, lezr, gtzr, eqzr, jmp, doJmp;

  // Assigning instruction encoding
  assign i = instruction[15];
  assign a = instruction[12];
  assign zx = instruction[11];
  assign nx = instruction[10];
  assign zy = instruction[9];
  assign ny = instruction[8];
  assign f = instruction[7];
  assign no = instruction[6];
  assign dA = instruction[5];
  assign dD = instruction[4];
  assign dM = instruction[3];
  assign leJ = instruction[2];
  assign eqJ = instruction[1];
  assign gtJ = instruction[0];

  // ALU input
  assign aluX = dRegister;
  assign aluY = (a) ? inM : aRegister;

  // ALU output
  alu alu_init (
    .x(aluX),
    .y(aluY),
    .zx(zx),
    .nx(nx),
    .zy(zy),
    .ny(ny),
    .f(f),
    .no(no),
    .out(aluOut),
    .zr(zr),
    .ng(ng)
  );
  assign outM = aluOut;
  
  // Memory address
  assign writeM = (dM & i) ? 1'b1 : 1'b0;
  assign addressM = aRegister[14:0];

  // Program counter
  assign po = ~zr & ~ng;
  assign lezr = leJ & ng;
  assign eqzr = eqJ & zr;
  assign gtzr = gtJ & po;
  assign jmp = lezr | eqzr | gtzr;
  assign doJmp = jmp & i;

  pc pc_init (
    .in(aRegister),
    .load(doJmp),
    .reset(reset),
    .clk(clk),
    .out(pc)
  );

  // Register A
  always_ff @(posedge clk) begin
    if (reset)
      aRegister <= 0;
    else if (!i)
      aRegister <= instruction;
    else if (dA & i)
      aRegister <= aluOut;
  end

  // Register D
  always_ff @(posedge clk) begin
    if (reset) 
      dRegister <= 0;
    else if (dD & i) 
      dRegister <= aluOut;
  end

  endmodule

