/**
 * The complete address space of the Hack computer's memory,
 * including RAM.
 * The chip facilitates read and write operations, as follows:
 *     Read:  out(t) = Memory[address(t)](t)
 *     Write: if load(t-1) then Memory[address(t-1)](t) = in(t-1)
 * In words: the chip always outputs the value stored at the memory 
 * location specified by address. If load==1, the in value is loaded 
 * into the memory location specified by address. This value becomes 
 * available through the out output from the next time step onward.
 * Address space rules:
 * Only the upper 16K+8K+1 words of the Memory chip are used. 
 * Access to address>0x6000 is invalid. 
 */

 module memory(input logic [15:0] in, input logic load, clk,
               input logic [14:0] address,
               output logic [15:0] out);

  logic [15:0] memory[0:32767];

  always_ff @(posedge clk) begin
    if (load) 
      ram[address] <= in;
    end 

  assign out = memory[address];

  endmodule
  
