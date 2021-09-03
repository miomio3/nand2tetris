// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@i
M=0  //i=0
@sum
M=0  //sum=0
@R2
M=0  //R2=0
@150
D=A
@R1
M=D
@R0
M=D

(LOOP)
@i
M=M+1  //i=i+1
@i
D=M  //D=i
@R1
D=D-M  //D=i-R1
@END1
D;JGT  //if i>R1 goto END1

@R0
D=M  //D=R0
@sum
M=D+M  //sum=sum+R0

@LOOP
0;JMP  //goto LOOP

(END1)
@sum
D=M  //D=sum
@R2
M=D  //R2=sum
@END2
0;JMP  //goto END2

(END2)
@END2
0;JMP  //無限ループ