// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.
// Put your code here.


// Initializing color vairable to 0
@color
M=0

// Infinite loop
(LOOP)
  @SCREEN
  D=A
  @pixels
  M=D

  @KBD
  D=M
  @BLACK
  D;JGT

  @color
  M=0
  @COLOR_SCREEN
  0;JMP

  (BLACK)
  @color
  M=-1

  (COLOR_SCREEN)
    @color
    D=M
    @pixels
    A=M
    M=D                        // Setting color of pixel

    @pixels
    M=M+1                      // Incrementing pixel address
    D=M

    @24576
    D=D-A
    @COLOR_SCREEN
    D;JLT

  @LOOP
  0;JMP
