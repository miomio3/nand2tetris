#include "nand.h"

out16	Mux4Way16(int a[16], int b[16], int c[16], int d[16], int sel[2])
{
	out16	outab;
	out16	outcd;

	outab = Mux16(a, b, sel[0]);
	outcd = Mux16(c, d, sel[0]);
	return(Mux16(outab.out, outcd.out, sel[1]));
}
/* 
int main(void)
{
	int		a[16];
	int		b[16];
	int		c[16];
	int		d[16];
	int		sel[2];
	int		i;
	out16	out;

	printf("a = 0, b = c = d = 1\nsel = 00\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 0;
		b[i] = 1;
		c[i] = 1;
		d[i] = 1;
	}
	sel[0] = 0;
	sel[1] = 0;
	out = Mux4Way16(a, b, c, d, sel);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("a = b = c = 1, d = 0\nsel = 11\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 1;
		c[i] = 1;
		d[i] = 0;
	}
	sel[0] = 1;
	sel[1] = 1;
	out = Mux4Way16(a, b, c, d, sel);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("a = c = d = 1, b = 0\nsel = 01\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 0;
		c[i] = 1;
		d[i] = 1;
	}
	sel[0] = 1;
	sel[1] = 0;
	out = Mux4Way16(a, b, c, d, sel);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	return(0);
} */