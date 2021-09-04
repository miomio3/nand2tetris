#include "nand.h"

sum_carry	FullAdder(int a, int b, int c)
{
	sum_carry	out1;
	sum_carry	out2;

	out1 = HalfAdder(a, b);
	out2.sum = Xor(out1.sum, c);
	out2.carry = Or(out1.carry, And(out2.sum, c));
	return(out2);
}
/* 
int main(void)
{
	sum_carry	out;

	printf("a = 0, b = 0, c = 0\n");
	out = FullAdder(0, 0, 0);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	printf("a = 0, b = 1, c = 0\n");
	out = FullAdder(0, 1, 0);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	printf("a = 1, b = 1, c = 0\n");
	out = FullAdder(1, 1, 0);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	printf("a = 1, b = 1, c = 1\n");
	out = FullAdder(1, 1, 1);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	return(0);
} */