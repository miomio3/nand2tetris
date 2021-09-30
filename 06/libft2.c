#include "asm.h"

int ft_isspace(char *p)
{
    if(*p == ' ')
        return(1);
    else
        return(0);
}