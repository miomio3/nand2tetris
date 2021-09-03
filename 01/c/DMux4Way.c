#include "nand.h"

out4	DMux4Way(int in, int sel[2])
{
	out2	outab;
	out2	outcd;
	out4	out;

	outab = DMux(in, sel[0]);
	outcd = DMux(in, sel[0]);
	out.a = And(outab.a, Not(sel[1]));
	out.b = And(outab.b, Not(sel[1]));
	out.c = And(outcd.a, sel[1]);
	out.d = And(outcd.b, sel[1]);
	return(out);
}
/* 
int main(void)
{
	out4	out;
	int		sel[2];

	printf("in = 1, sel = 00\n");
	sel[0] = 0;
	sel[1] = 0;
	out = DMux4Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	printf("in = 1, sel = 01\n");
	sel[0] = 1;
	sel[1] = 0;
	out = DMux4Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	printf("in = 1, sel = 10\n");
	sel[0] = 0;
	sel[1] = 1;
	out = DMux4Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	printf("in = 1, sel = 11\n");
	sel[0] = 1;
	sel[1] = 1;
	out = DMux4Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	return(0);
} */