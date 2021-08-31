#include "nand.h"
#include <stdio.h>

int And(int a, int b)
{
    int nout;

    nout = Nand(a, b);
    return(Not(nout));
}
/* 
int main(void)
{
    printf("%d\n", And(0,0));
    printf("%d\n", And(0,1));
    printf("%d\n", And(1,0));
    printf("%d\n", And(1,1));
} */