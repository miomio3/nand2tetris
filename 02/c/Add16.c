#include "nand.h"

out16	Add16(int a[16], int b[16])
{
	out16		out;
	sum_carry	w1;
	sum_carry	w2;

	w2 = HalfAdder(a[0], b[0]);
	out.out[0] = w2.sum;
	w1 = FullAdder(w2.carry, a[1], b[1]);
	out.out[1] = w1.sum;
	w2 = FullAdder(w1.carry, a[2], b[2]);
	out.out[2] = w2.sum;
	w1 = FullAdder(w2.carry, a[3], b[3]);
	out.out[3] = w1.sum;
	w2 = FullAdder(w1.carry, a[4], b[4]);
	out.out[4] = w2.sum;
	w1 = FullAdder(w2.carry, a[5], b[5]);
	out.out[5] = w1.sum;
	w2 = FullAdder(w1.carry, a[6], b[6]);
	out.out[6] = w2.sum;
	w1 = FullAdder(w2.carry, a[7], b[7]);
	out.out[7] = w1.sum;
	w2 = FullAdder(w1.carry, a[8], b[8]);
	out.out[8] = w2.sum;
	w1 = FullAdder(w2.carry, a[9], b[9]);
	out.out[9] = w1.sum;
	w2 = FullAdder(w1.carry, a[10], b[10]);
	out.out[10] = w2.sum;
	w1 = FullAdder(w2.carry, a[11], b[11]);
	out.out[11] = w1.sum;
	w2 = FullAdder(w1.carry, a[12], b[12]);
	out.out[12] = w2.sum;
	w1 = FullAdder(w2.carry, a[13], b[13]);
	out.out[13] = w1.sum;
	w2 = FullAdder(w1.carry, a[14], b[14]);
	out.out[14] = w2.sum;
	w1 = FullAdder(w2.carry, a[15], b[15]);
	out.out[15] = w1.sum;
	return(out);
}

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
	out = Add16(a, b);
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
	out = Add16(a, b);
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
	out = Add16(a, b);
	i = -1;
	while(++i < 16)
		printf("out%d = %d\n", i, out.out[i]);
	return(0);
}