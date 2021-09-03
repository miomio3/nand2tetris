#include "nand.h"

out16	And16(int a[16], int b[16])
{
	out16	out;

	out.out[0] = And(a[0], b[0]);
	out.out[1] = And(a[1], b[1]);
	out.out[2] = And(a[2], b[2]);
	out.out[3] = And(a[3], b[3]);
	out.out[4] = And(a[4], b[4]);
	out.out[5] = And(a[5], b[5]);
	out.out[6] = And(a[6], b[6]);
	out.out[7] = And(a[7], b[7]);
	out.out[8] = And(a[8], b[8]);
	out.out[9] = And(a[9], b[9]);
	out.out[10] = And(a[10], b[10]);
	out.out[11] = And(a[11], b[11]);
	out.out[12] = And(a[12], b[12]);
	out.out[13] = And(a[13], b[13]);
	out.out[14] = And(a[14], b[14]);
	out.out[15] = And(a[15], b[15]);
	return(out);
}
/* 
int main(void)
{
	int		a[16];
	int		b[16];
	int		i;
	out16	out;

	printf("a = b = 0\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 0;
		b[i] = 0;
	}
	out = And16(a, b);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("a = 1, b = 0\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 0;
	}
	out = And16(a, b);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	printf("a = 1, b = 1\n");
	i = -1;
	while(++i < 16)
	{
		a[i] = 1;
		b[i] = 1;
	}
	out = And16(a, b);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	return(0);
} */