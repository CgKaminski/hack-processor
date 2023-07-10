/**
 * 8-way demultiplexor:
 * {a, b, c, d, e, f, g, h} = {in, 0, 0, 0, 0, 0, 0, 0} if sel == 000
 *                            {0, in, 0, 0, 0, 0, 0, 0} if sel == 001
 *                            etc.
 *                            {0, 0, 0, 0, 0, 0, 0, in} if sel == 111
 */


module dmux8way(input logic in, input logic [2:0] sel, output logic a, output logic b, output logic c, output logic d, output logic e, output logic f, output logic g, output logic h);


  
  assign a = (sel === 3'b000) ? in : 1'b0;
  assign b = (sel === 3'b001) ? in : 1'b0;
  assign c = (sel === 3'b010) ? in : 1'b0;
  assign d = (sel === 3'b011) ? in : 1'b0;
  assign e = (sel === 3'b100) ? in : 1'b0;
  assign f = (sel === 3'b101) ? in : 1'b0;
  assign g = (sel === 3'b110) ? in : 1'b0;
  assign h = (sel === 3'b111) ? in : 1'b0;

endmodule

