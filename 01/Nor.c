#include "nand.h"

int Nor(int a, int b)
{
    return(And(Not(a), Not(b)));
}
/* 
int main(void)
{
    printf("%d\n", Nor(0, 0));
    printf("%d\n", Nor(1, 0));
    printf("%d\n", Nor(0, 1));
    printf("%d\n", Nor(1, 1));
    return(0);
} */