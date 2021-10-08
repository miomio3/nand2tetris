#include "nand.h"

sum_carry	HalfAdder(int a, int b)
{
	sum_carry	out;

	out.sum = Xor(a, b);
	out.carry = And(a, b);
	return(out);
}
