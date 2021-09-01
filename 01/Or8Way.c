#include "nand.h"

int	Or8Way(int in[8])
{
	int or0;
	int or1;

	or0 = Or(Or(in[0], in[1]), Or(in[2], in[3]));
	or1 = Or(Or(in[4], in[5]), Or(in[6], in[7]));
	return(Or(or0, or1));
}
/* 
int main(void)
{
	int	i;
	int	in[8];

	i = -1;
	while(++i < 8)
		in[i] = 0;
	printf("all 0 = %d\n", Or8Way(in));
	i = -1;
	while(++i < 8)
		in[i] = 1;
	printf("all 1 = %d\n", Or8Way(in));
	i = -1;
	while(++i < 7)
		in[i] = 1;
	in[7] = 0;
	printf("only in[7] 0 =  %d\n", Or8Way(in));
} */