#ifndef NAND_H
#define NAND_H

#include <stdio.h>

typedef struct	out2
{
	int	a;
	int	b;
}out2;

typedef	struct	out16
{
	int out[16];
}out16;

typedef	struct	out4
{
	int	a;
	int	b;
	int	c;
	int	d;
}out4;

typedef struct	out8
{
	int	a;
	int	b;
	int	c;
	int	d;
	int e;
	int	f;
	int	g;
	int	h;
}out8;

typedef struct sum_carry
{
	int sum;
	int carry;
}sum_carry;

typedef struct ALUout
{
	int out[16];
	int zr;
	int ng;
}ALUout;


int			Nand(int a, int b);
int			Not(int in);
int			And(int a, int b);
int			Nor(int a, int b);
int			Or(int a, int b);
int			Xor(int a, int b);
int			Mux(int a, int b, int sel);
out2		DMux(int in, int sel);
out16		Not16(int in[16]);
out16		Or16(int a[16], int b[16]);
out16		And16(int a[16], int b[16]);
out16		Mux16(int a[16], int b[16], int sel);
int			Or8Way(int in[8]);
out16		Mux4Way16(int a[16], int b[16], int c[16], int d[16], int sel[2]);
out4		DMux4Way(int in, int sel[2]);
sum_carry	HalfAdder(int a, int b);
sum_carry	FullAdder(int a, int b, int c);
out16		Add16(int a[16], int b[16]);
out16		Inc16(int a[16]);
ALUout		ALU(int x[16], int y[16], int zx, int nx, int zy, int ny, int f, int no);

#endif