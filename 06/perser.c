#include "asm.h"

char    *nl(char *p)
{
    while(*p != '\n')
        p++;
    p++;
    return(p);
}

void    perser(char *assembly)
{
    char    *p;

    p = assembly;
    while(p)
    {
        while(ft_isspace(p))
            p++;
        if((*p == '/' && *p == '/') || *p == '\n')
        {
            p = nl(p);
            continue;
        }
        
    }
}