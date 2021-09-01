#include "nand.h"

a_b	DMux(int sel, int in)
{
	a_b	out;

	out.a = And(in, Not(sel));
	out.b = And(in, sel);
	return(out);
}
/* 
int	main(void)
{
	printf("sel = 0\n");
	printf("in = 0 a = %d b = %d\n", DMux(0, 0).a, DMux(0, 0).b);
	printf("in = 1 a = %d b = %d\n", DMux(0, 1).a, DMux(0, 1).b);
	printf("sel = 1\n");
	printf("in = 0 a = %d b = %d\n", DMux(1, 0).a, DMux(1, 0).b);
	printf("in = 1 a = %d b = %d\n", DMux(1, 1).a, DMux(1, 1).b);
} */