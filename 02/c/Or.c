#include "nand.h"

int Or(int a, int b)
{
    return(Not(Nor(a, b)));
}
/* 
int main(void)
{
    printf("%d\n", Or(0, 0));
    printf("%d\n", Or(1, 0));
    printf("%d\n", Or(0, 1));
    printf("%d\n", Or(1, 1));
    return(0);
} */