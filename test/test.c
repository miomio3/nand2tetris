#include "asm.h"

int    add_symbol(t_symbols **symbols, char *s, int memory)
{
    t_symbols   *t;
    t_symbols   **p;

    t = malloc(sizeof(t_symbols));
    if(t == NULL)
        return(ERROR);
    t->symbol = strdup(s);
    t->memory = memory;
    t->next = NULL;
    while(*symbols != NULL)
        symbols = &((*symbols)->next);
    *symbols = t;
    return(NOERROR);
}

t_symbols    *init_symbol_table(void)
{
    t_symbols 	**symbols;
	t_symbols	*head;

	symbols = &head;
	*symbols = NULL;
    add_symbol(symbols, "SP", 0);
    add_symbol(symbols, "LCL", 1);
    printf("%d\n", head->memory);
    printf("%s\n", head->symbol);
    printf("%d\n", head->next->memory);
    printf("%s\n", head->next->symbol);
}

int main(void)
{
	init_symbol_table();
	return(0);
}