/// Multiplexor
// ex. out = a if sel == 0
//         b if sel == 1


module mux(input logic a, input logic b, input logic sel, output logic out);

  assign out = a & ~sel | b & sel;

  endmodule

