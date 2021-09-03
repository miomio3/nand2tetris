#include "nand.h"

out8	DMux8Way(int in, int sel[3])
{
	int		sel2[2];
	out8	out;
	out4	outa2d;
	out4	oute2h;

	sel2[0] = sel[0];
	sel2[1] = sel[1];
	outa2d = DMux4Way(in, sel2);
	oute2h = DMux4Way(in, sel2);
	out.a = And(outa2d.a, Not(sel[2]));
	out.b = And(outa2d.b, Not(sel[2]));
	out.c = And(outa2d.c, Not(sel[2]));
	out.d = And(outa2d.d, Not(sel[2]));
	out.e = And(outa2d.a, sel[2]);
	out.f = And(outa2d.b, sel[2]);
	out.g = And(outa2d.c, sel[2]);
	out.h = And(outa2d.d, sel[2]);
	return(out);
}
/* 
int main(void)
{
	out8	out;
	int		sel[3];

	printf("in = 1, sel = 000\n");
	sel[0] = 0;
	sel[1] = 0;
	sel[2] = 0;
	out = DMux8Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	printf("e = %d, f = %d, g = %d, h = %d\n", out.e, out.f, out.g, out.h);
	printf("in = 1, sel = 100\n");
	sel[0] = 0;
	sel[1] = 0;
	sel[2] = 1;
	out = DMux8Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	printf("e = %d, f = %d, g = %d, h = %d\n", out.e, out.f, out.g, out.h);
	printf("in = 1, sel = 010\n");
	sel[0] = 0;
	sel[1] = 1;
	sel[2] = 0;
	out = DMux8Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	printf("e = %d, f = %d, g = %d, h = %d\n", out.e, out.f, out.g, out.h);
	printf("in = 1, sel = 111\n");
	sel[0] = 1;
	sel[1] = 1;
	sel[2] = 1;
	out = DMux8Way(1, sel);
	printf("a = %d, b = %d, c = %d, d = %d\n", out.a, out.b, out.c, out.d);
	printf("e = %d, f = %d, g = %d, h = %d\n", out.e, out.f, out.g, out.h);
	return(0);
}  */