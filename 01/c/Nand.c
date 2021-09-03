#include "nand.h"

int Nand(int a, int b)
{
    if(a == 0 && b == 0)
        return(1);
    else if((a == 0 && b == 1) || (a == 1 && b == 0))
        return(1);
    else
        return(0);
}
/* 
int main(void)
{
    printf("%d\n", Nand(0,0));
    printf("%d\n", Nand(0,1));
    printf("%d\n", Nand(1,0));
    printf("%d\n", Nand(1,1));
} */