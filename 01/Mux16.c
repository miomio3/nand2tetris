#include "nand.h"

out16	Mux16(int a[16], int b[16], int sel)
{
	out16	out;

	out.out[0] = Mux(a[0], b[0], sel);
	out.out[1] = Mux(a[1], b[1], sel);
	out.out[2] = Mux(a[2], b[2], sel);
	out.out[3] = Mux(a[3], b[3], sel);
	out.out[4] = Mux(a[4], b[4], sel);
	out.out[5] = Mux(a[5], b[5], sel);
	out.out[6] = Mux(a[6], b[6], sel);
	out.out[7] = Mux(a[7], b[7], sel);
	out.out[8] = Mux(a[8], b[8], sel);
	out.out[9] = Mux(a[9], b[9], sel);
	out.out[10] = Mux(a[10], b[10], sel);
	out.out[11] = Mux(a[11], b[11], sel);
	out.out[12] = Mux(a[12], b[12], sel);
	out.out[13] = Mux(a[13], b[13], sel);
	out.out[14] = Mux(a[14], b[14], sel);
	out.out[15] = Mux(a[15], b[15], sel);
	return(out);
}
/* 
int main(void)
{
	int		a[16];
	int		b[16];
	int		i;
	out16	out;

	printf("a = b = 0\nsel = 0\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 0;
		b[i] = 0;
	}
	out = Mux16(a, b, 0);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("a = 1, b = 0\nsel = 0\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 0;
	}
	out = Mux16(a, b, 0);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("a = 1, b = 0\nsel = 1\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 0;
	}
	out = Mux16(a, b, 1);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	return(0);
} */