/**
 * A 16-bit counter with load and reset control bits.
 * if      (reset[t] == 1) out[t+1] = 0
 * else if (load[t] == 1)  out[t+1] = in[t]
 * else if (inc[t] == 1)   out[t+1] = out[t] + 1  (integer addition)
 * else                    out[t+1] = out[t]
 */

module pc(input logic [15:0] in,
          input logic load, reset, clk,
          output logic [15:0] out);

  always_ff @(posedge clk)
    if (reset) out <= 0;
    else if (load) out <= in;
    else out <= out + 1;

endmodule

