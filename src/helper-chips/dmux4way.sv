/**
 * 4-way demultiplexor:
 * {a, b, c, d} = {in, 0, 0, 0} if sel == 00
 *                {0, in, 0, 0} if sel == 01
 *                {0, 0, in, 0} if sel == 10
 *                {0, 0, 0, in} if sel == 11
 */


module dmux4way(input logic in, input logic [1:0] sel, output logic a, b, c, d);

  assign a = (sel === 2'b00) ? in : 1'b0;
  assign b = (sel === 2'b01) ? in : 1'b0;
  assign c = (sel === 2'b10) ? in : 1'b0;
  assign d = (sel === 2'b11) ? in : 1'b0;

endmodule

