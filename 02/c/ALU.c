#include "nand.h"

ALUout	ALU(int x[16], int y[16], int zx, int nx, int zy, int ny, int f, int no)
{
	ALUout	aluout;
	out16	xout;
	out16	zero;
	out16	yout;
	out16	Andout;
	out16	Addout;
	out16	out;
	int		sel[2];

	zero = And16(Not16(x).out, x);
	xout = Mux16(x, zero.out, zx);
	xout = Mux16(xout.out, Not16(xout.out).out,nx);
	yout = Mux16(y, zero.out, zy);
	yout = Mux16(xout.out, Not16(xout.out).out,ny);
	sel[0] = f;
	sel[1] = no;
	Andout = And16(xout.out, yout.out);
	Addout = Add16(xout.out, yout.out);
	out = Mux4Way16(Andout.out, Addout.out, Not16(Andout.out).out, Not16(Addout.out).out, sel);
	aluout.out[0] = out.out[0];
	aluout.out[1] = out.out[1];
	aluout.out[2] = out.out[2];
	aluout.out[3] = out.out[3];
	aluout.out[4] = out.out[4];
	aluout.out[5] = out.out[5];
	aluout.out[6] = out.out[6];
	aluout.out[7] = out.out[7];
	aluout.out[8] = out.out[8];
	aluout.out[9] = out.out[9];
	aluout.out[10] = out.out[10];
	aluout.out[11] = out.out[11];
	aluout.out[12] = out.out[12];
	aluout.out[13] = out.out[13];
	aluout.out[14] = out.out[14];
	aluout.out[15] = out.out[15];
	aluout.ng = aluout.out[15];
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

int main(void)
{
	ALUout	out;
	int		x[16];
	int		y[16];
	int		i;

	printf("no = 1, other = 0\n");
	i = 0;
	while(i < 16)
		x[i++] = 0;
	i = 0;
	while(i < 16)
		y[i++] = 0;
	out = ALU(x, y, 0, 0, 0, 0, 0, 1);
	i = 0;
	while(i < 16)
		printf("%d ", out.out[i++]);
	printf("\nzr = %d, ng = %d\n", out.zr, out.ng);

	printf("\nno,f = 1, other = 0\n");
	i = 0;
	while(i < 16)
		x[i++] = 0;
	i = 0;
	while(i < 16)
		y[i++] = 0;
	out = ALU(x, y, 0, 0, 0, 0, 1, 1);
	i = 0;
	while(i < 16)
		printf("%d ", out.out[i++]);
	printf("\nzr = %d, ng = %d\n", out.zr, out.ng);

	printf("\nzx = 1, other = 0\n");
	i = 0;
	while(i < 16)
		x[i++] = 0;
	i = 0;
	while(i < 16)
		y[i++] = 0;
	out = ALU(x, y, 1, 0, 0, 0, 0, 0);
	i = 0;
	while(i < 16)
		printf("%d ", out.out[i++]);
	printf("\nzr = %d, ng = %d\n", out.zr, out.ng);

	printf("\nnx = 1, other = 0\n");
	i = 0;
	while(i < 16)
		x[i++] = 0;
	i = 0;
	while(i < 16)
		y[i++] = 0;
	out = ALU(x, y, 0, 1, 0, 0, 0, 0);
	i = 0;
	while(i < 16)
		printf("%d ", out.out[i++]);
	printf("\nzr = %d, ng = %d\n", out.zr, out.ng);

	printf("\nzy = 1, other = 0\n");
	i = 0;
	while(i < 16)
		x[i++] = 0;
	i = 0;
	while(i < 16)
		y[i++] = 0;
	out = ALU(x, y, 0, 0, 1, 0, 0, 0);
	i = 0;
	while(i < 16)
		printf("%d ", out.out[i++]);
	printf("\nzr = %d, ng = %d\n", out.zr, out.ng);

	printf("\nny = 1, other = 0\n");
	i = 0;
	while(i < 16)
		x[i++] = 0;
	i = 0;
	while(i < 16)
		y[i++] = 0;
	out = ALU(x, y, 0, 0, 0, 1, 0, 0);
	i = 0;
	while(i < 16)
		printf("%d ", out.out[i++]);
	printf("\nzr = %d, ng = %d\n", out.zr, out.ng);
	return(0);
}