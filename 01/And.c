#include "nand.h"

int And(int a, int b)
{
    return(Not(Nand(a, b)));
}
/* 
int main(void)
{
    printf("%d\n", And(0,0));
    printf("%d\n", And(0,1));
    printf("%d\n", And(1,0));
    printf("%d\n", And(1,1));
} */