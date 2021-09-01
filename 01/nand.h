#ifndef NAND_H
#define NAND_H

#include <stdio.h>

typedef struct	a_b
{
	int	a;
	int	b;
}a_b;

typedef	struct out16
{
	int out[16];
}out16;


int		Nand(int a, int b);
int		Not(int in);
int		And(int a, int b);
int		Nor(int a, int b);
int		Or(int a, int b);
int		Xor(int a, int b);
int		Mux(int a, int b, int sel);
a_b		DMux(int sel, int in);
out16	Not16(int in[16]);
out16	Or16(int a[16], int b[16]);
out16	And16(int a[16], int b[16]);
out16	Mux16(int a[16], int b[16], int sel);
int		Or8Way(int in[8]);

#endif