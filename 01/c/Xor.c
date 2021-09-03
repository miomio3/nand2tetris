#include "nand.h"

int Xor(int a, int b)
{
    return(And(Or(a, b), Nand(a, b)));
}
/* 
int main(void)
{
    printf("%d\n", Xor(0, 0));
    printf("%d\n", Xor(1, 0));
    printf("%d\n", Xor(0, 1));
    printf("%d\n", Xor(1, 1));
    return(0);
} */