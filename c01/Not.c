#include "nand.h"

int Not(int in)
{
    return(Nand(in, in));
}
/* 
int main(void)
{
    printf("%d\n", Not(1));
    printf("%d\n", Not(0));
    return(0);
} */