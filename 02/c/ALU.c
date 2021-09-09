#include "nand.h"

ALUout	ALU(int x[16], int y[16], int zx, int nx, int zy, int ny, int f, int no)
{
	ALUout	aluout;
	out16	xout;
	out16	zero;
	out16	yout;
	int		sel[2];

	zero = And16(Not16(x).out, x);
	xout = Mux16(x, Not16(x).out,nx);
	xout = Mux16(xout.out, zero.out, zx);
	yout = Mux16(y, Not16(y).out,ny);
	yout = Mux16(yout.out, zero.out, zy);
	sel[0] = f;
	sel[1] = no;
	aluout.out[0] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[0];
	aluout.out[1] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[1];
	aluout.out[2] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[2];
	aluout.out[3] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[3];
	aluout.out[4] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[4];
	aluout.out[5] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[5];
	aluout.out[6] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[6];
	aluout.out[7] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[7];
	aluout.out[8] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[8];
	aluout.out[9] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[9];
	aluout.out[10] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[10];
	aluout.out[11] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[11];
	aluout.out[12] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[12];
	aluout.out[13] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[13];
	aluout.out[14] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[14];
	aluout.out[15] = Mux4Way16(And16(xout.out, yout.out).out, Add16(xout.out, yout.out).out, Not16(And16(xout.out, yout.out).out).out, Not16(Add16(xout.out, yout.out).out).out, sel).out[15];
	aluout.ng = aluout.out[0];
	aluout.zr = And(aluout.zr, aluout.out[0]);
	aluout.zr = And(aluout.zr, aluout.out[1]);
	aluout.zr = And(aluout.zr, aluout.out[2]);
	aluout.zr = And(aluout.zr, aluout.out[3]);
	aluout.zr = And(aluout.zr, aluout.out[4]);
	aluout.zr = And(aluout.zr, aluout.out[5]);
	aluout.zr = And(aluout.zr, aluout.out[6]);
	aluout.zr = And(aluout.zr, aluout.out[7]);
	aluout.zr = And(aluout.zr, aluout.out[8]);
	aluout.zr = And(aluout.zr, aluout.out[9]);
	aluout.zr = And(aluout.zr, aluout.out[10]);
	aluout.zr = And(aluout.zr, aluout.out[11]);
	aluout.zr = And(aluout.zr, aluout.out[12]);
	aluout.zr = And(aluout.zr, aluout.out[13]);
	aluout.zr = And(aluout.zr, aluout.out[14]);
	aluout.zr = And(aluout.zr, aluout.out[15]);
	return(aluout);
}
