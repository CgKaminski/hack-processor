module dmux_testbench;

  logic in, sel, a, b;

  // Instantiate the module under test
  dmux dut(in, sel, a, b);

  initial begin
    in = 1'b1;
    sel = 1'b0;
    #10;
    assert(a === 1'b1 && b === 1'b0);

    in = 1'b1;
    sel = 1'b1;
    #10;
    assert(a === 1'b0 && b === 1'b1);
  end
endmodule

