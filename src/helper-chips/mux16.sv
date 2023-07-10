/**
 * 16-bit multiplexor: 
 * for i = 0..15 out[i] = a[i] if sel == 0 
 *                        b[i] if sel == 1
 */


module mux16(input [15:0] a, input [15:0] b, input sel, output [15:0] out);

  assign out[0] = a[0] & ~sel | b[0] & sel;
  assign out[1] = a[1] & ~sel | b[1] & sel;
  assign out[2] = a[2] & ~sel | b[2] & sel;
  assign out[3] = a[3] & ~sel | b[3] & sel;
  assign out[4] = a[4] & ~sel | b[4] & sel;
  assign out[5] = a[5] & ~sel | b[5] & sel;
  assign out[6] = a[6] & ~sel | b[6] & sel;
  assign out[7] = a[7] & ~sel | b[7] & sel;
  assign out[8] = a[8] & ~sel | b[8] & sel;
  assign out[9] = a[9] & ~sel | b[9] & sel;
  assign out[10] = a[10] & ~sel | b[10] & sel;
  assign out[11] = a[11] & ~sel | b[11] & sel;
  assign out[12] = a[12] & ~sel | b[12] & sel;
  assign out[13] = a[13] & ~sel | b[13] & sel;
  assign out[14] = a[14] & ~sel | b[14] & sel;
  assign out[15] = a[15] & ~sel | b[15] & sel;
endmodule
