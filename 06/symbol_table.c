#include "asm.h"

int    add_symbol(t_symbols **symbols, char *s, int memory)
{
    t_symbols   *t;
    t_symbols   *p;

    t = malloc(sizeof(t_symbols));
    if(t == NULL)
        return(ERROR);
    t->symbol = ft_strdup(s);
    t->memory = memory;
    t->next = NULL;
    p = *symbols;
    while(p != NULL)
        p = p->next;
    p = t;
    return(NOERROR);
}

t_symbols    *init_symbol_table(void)
{
    t_symbols  *symbols;

    symbols = NULL;
    add_symbol(&symbols, "SP", 0);
    add_symbol(&symbols, "LCL", 1);
    printf("%d\n", symbols->memory);
    printf("%s\n", symbols->symbol);
    printf("%d\n", symbols->next->memory);
    printf("%s\n", symbols->next->symbol);
}