/**
 * 4-way 16-bit multiplexor:
 * out = a if sel == 00
 *       b if sel == 01
 *       c if sel == 10
 *       d if sel == 11
 */


module mux4way16(input [15:0] a, b, c, d, input [1:0] sel, output reg [15:0] out);

  always @ (a or b or c or d or sel)
    begin
      case (sel)
        2'b00: out = a;
        2'b01: out = b;
        2'b10: out = c;
        2'b11: out = d;
      endcase
    end
endmodule
