#include "nand.h"

out16	Or16(int a[16], int b[16])
{
	out16	out;

	out.out[0] = Or(a[0], b[0]);
	out.out[1] = Or(a[1], b[1]);
	out.out[2] = Or(a[2], b[2]);
	out.out[3] = Or(a[3], b[3]);
	out.out[4] = Or(a[4], b[4]);
	out.out[5] = Or(a[5], b[5]);
	out.out[6] = Or(a[6], b[6]);
	out.out[7] = Or(a[7], b[7]);
	out.out[8] = Or(a[8], b[8]);
	out.out[9] = Or(a[9], b[9]);
	out.out[10] = Or(a[10], b[10]);
	out.out[11] = Or(a[11], b[11]);
	out.out[12] = Or(a[12], b[12]);
	out.out[13] = Or(a[13], b[13]);
	out.out[14] = Or(a[14], b[14]);
	out.out[15] = Or(a[15], b[15]);
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
	out = Or16(a, b);
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
	out = Or16(a, b);
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
	out = Or16(a, b);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	return(0);
} */