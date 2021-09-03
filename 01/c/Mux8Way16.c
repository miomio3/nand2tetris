#include "nand.h"

out16	Mux8Way16(int a[16], int b[16], int c[16], int d[16], int e[16], int f[16], int g[16], int h[16], int sel[3])
{
	int	sel2[2];
	out16	out1;
	out16	out2;

	sel2[0] = sel[0];
	sel2[1] = sel[1];
	out1 = Mux4Way16(a, b, c, d, sel2);
	out2 = Mux4Way16(e, f, g, h, sel2);
	return(Mux16(out1.out, out2.out, sel[2]));
}
/* 
int main(void)
{
	int		a[16];
	int		b[16];
	int		c[16];
	int		d[16];
	int		e[16];
	int		f[16];
	int		g[16];
	int		h[16];
	int		sel[3];
	int		i;
	out16	out;

	printf("a = 0, others = 1\nsel = 00\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 0;
		b[i] = 1;
		c[i] = 1;
		d[i] = 1;
		e[i] = 1;
		f[i] = 1;
		g[i] = 1;
		h[i] = 1;
	}
	sel[0] = 0;
	sel[1] = 0;
	sel[2] = 0;
	out = Mux8Way16(a, b, c, d, e, f, g, h, sel);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("e = 0, others = 1\nsel = 11\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 1;
		c[i] = 1;
		d[i] = 1;
		e[i] = 0;
		f[i] = 1;
		g[i] = 1;
		h[i] = 1;
	}
	sel[0] = 0;
	sel[1] = 0;
	sel[2] = 1;
	out = Mux8Way16(a, b, c, d, e, f, g, h, sel);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("h = 0, others = 1\nsel = 01\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 1;
		c[i] = 1;
		d[i] = 1;
		e[i] = 1;
		f[i] = 1;
		g[i] = 1;
		h[i] = 0;
	}
	sel[0] = 1;
	sel[1] = 1;
	sel[2] = 1;
	out = Mux8Way16(a, b, c, d, e, f, g, h, sel);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	return(0);
} */