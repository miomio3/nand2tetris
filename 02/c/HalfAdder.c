#include "nand.h"

sum_carry	HalfAdder(int a, int b)
{
	sum_carry	out;

	out.sum = Xor(a, b);
	out.carry = And(a, b);
	return(out);
}
/* 
int main(void)
{
	sum_carry	out;

	printf("a = 0, b = 0\n");
	out = HalfAdder(0, 0);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	printf("a = 0, b = 1\n");
	out = HalfAdder(0, 1);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	printf("a = 1, b = 0\n");
	out = HalfAdder(1, 0);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	printf("a = 1, b = 1\n");
	out = HalfAdder(1, 1);
	printf("sum = %d, carry = %d\n", out.sum, out.carry);
	return(0);
} */