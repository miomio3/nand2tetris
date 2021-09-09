#include "nand.h"

out16	Inc16(int a[16])
{
	out16		out;
	sum_carry	out2;

	out2 = HalfAdder(a[0], 1);
	out.out[0] = out2.sum;
	out2 = HalfAdder(a[1], out2.carry);
	out.out[1] = out2.sum;
	out2 = HalfAdder(a[2], out2.carry);
	out.out[2] = out2.sum;
	out2 = HalfAdder(a[3], out2.carry);
	out.out[3] = out2.sum;
	out2 = HalfAdder(a[4], out2.carry);
	out.out[4] = out2.sum;
	out2 = HalfAdder(a[5], out2.carry);
	out.out[5] = out2.sum;
	out2 = HalfAdder(a[6], out2.carry);
	out.out[6] = out2.sum;
	out2 = HalfAdder(a[7], out2.carry);
	out.out[7] = out2.sum;
	out2 = HalfAdder(a[8], out2.carry);
	out.out[8] = out2.sum;
	out2 = HalfAdder(a[9], out2.carry);
	out.out[9] = out2.sum;
	out2 = HalfAdder(a[10], out2.carry);
	out.out[10] = out2.sum;
	out2 = HalfAdder(a[11], out2.carry);
	out.out[11] = out2.sum;
	out2 = HalfAdder(a[12], out2.carry);
	out.out[12] = out2.sum;
	out2 = HalfAdder(a[13], out2.carry);
	out.out[13] = out2.sum;
	out2 = HalfAdder(a[14], out2.carry);
	out.out[14] = out2.sum;
	out2 = HalfAdder(a[15], out2.carry);
	out.out[15] = out2.sum;
	return(out);
}
/* 
int main(void)
{
	int		i;
	int		a[16];
	out16	out;

	printf("all 0\n");
	i = 0;
	while(i < 16)
		a[i++] = 0;
	out = Inc16(a);
	i = 0;
	while(i < 16)
		printf("%d\n", out.out[i++]);
	printf("\nall 1\n");
	i = 0;
	while(i < 16)
		a[i++] = 1;
	out = Inc16(a);
	i = 0;
	while(i < 16)
		printf("%d\n", out.out[i++]);
	printf("\nonly 0 = 1, other = 0\n");
	a[0] = 1;
	i = 1;
	while(i < 16)
		a[i++] = 0;
	out = Inc16(a);
	i = 0;
	while(i < 16)
		printf("%d\n", out.out[i++]);
} */