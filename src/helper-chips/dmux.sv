// Demultiplexor
// ex. {a, b} = {in, 0} if sel == 0
//              {0, in} if sel == 1


module dmux(input logic in, input logic sel, output logic a, output logic b);

  assign a = in & ~sel;
  assign b = in & sel;

  endmodule

