#include "nand.h"

int	Mux(int a, int b, int sel)
{
	int	asel;
	int	bsel;

	asel = And(a, Not(sel));
	bsel = And(b, sel);
	return(Or(asel, bsel));
}
/* 
int	main(void)
{
	printf("%d\n", Mux(0,0,0));
	printf("%d\n", Mux(0,1,0));
	printf("%d\n", Mux(1,0,0));
	printf("%d\n", Mux(1,1,0));
	printf("%d\n", Mux(0,0,1));
	printf("%d\n", Mux(0,1,1));
	printf("%d\n", Mux(1,0,1));
	printf("%d\n", Mux(1,1,1));
	return(0);
} */