/**
 * The ALU (Arithmetic Logic Unit).
 * Computes one of the following functions:
 * x+y, x-y, y-x, 0, 1, -1, x, y, -x, -y, !x, !y,
 * x+1, y+1, x-1, y-1, x&y, x|y on two 16-bit inputs, 
 * according to 6 input bits denoted zx,nx,zy,ny,f,no.
 * In addition, the ALU computes two 1-bit outputs:
 * if the ALU output == 0, zr is set to 1; otherwise zr is set to 0;
 * if the ALU output < 0, ng is set to 1; otherwise ng is set to 0.
 */

module alu(
  input logic [15:0] x, y,
  input logic zx, nx, zy, ny, f, no,
  output logic [15:0] out,
  output logic zr, ng);

  logic [15:0] x1, x2, y1, y2, out1; 

  
  // Pre-computation for x and y
  assign x1 = (zx) ? 16'b0 : x;
  assign x2 = (nx) ? ~x1 : x1;
  assign y1 = (zy) ? 16'b0 : y;
  assign y2 = (ny) ? ~y1 : y1;

  // Compute the output
  assign out1 = (f) ? x2 + y2 : x2 & y2; 

  // Post-computation for out
  assign out = (no) ? ~out1 : out1;
  
  // Compute zr and ng
  assign zr = (out === 16'b0);
  assign ng = (out[15] === 1);

  endmodule

