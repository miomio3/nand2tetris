#include "asm.h"

void    add_symbol(t_symbols **symbols, char *s, int memory)
{
    t_symbols   *t;

    t = malloc(sizeof(t_symbols));
    t->symbol = ft_strdup(s);
    t->memory = memory;
    t->next = NULL;
    while(*symbols != NULL)
        symbols = &((*symbols)->next);
    *symbols = t;
}

void	add_r(t_symbols **symbols)
{
	char	*s;
	int		i;
	int		ten;
	int		si;

	s = malloc(sizeof(char) * 4);
	si = 0;
	s[si] = 'R';
	si++;
	i = 0;
	while(i < 16)
	{
		si = 1;
		ten = i / 10;
		if(ten > 0)
			s[si++] = '0' + ten;
		s[si++] = '0' + i % 10;
		s[si] = '\0';
		add_symbol(symbols, s, i);
		i++;
	}
}

t_symbols    *init_symbol_table(char *assembly, token *Token)
{
    t_symbols 	**symbols;
	t_symbols	*head;

	symbols = &head;
	*symbols = NULL;
    add_symbol(symbols, "SP", 0);
    add_symbol(symbols, "LCL", 1);
    add_symbol(symbols, "ARG", 2);
	add_symbol(symbols, "THIS", 3);
	add_symbol(symbols, "THAT", 4);
	add_symbol(symbols, "SCREEN", 16384);
	add_symbol(symbols, "KBD", 24576);
	add_r(symbols);
	add_para(symbols, assembly);
	return(head);
}

int	search_symbol(t_symbols **symbols, char *var)
{
	t_symbols	*p;
	int			prev_mem;

	p = *symbols;
	while(p != NULL)
	{
		if(ft_strcmp(p->symbol, var) == 0)
			return(p->memory);
		prev_mem = p->memory;
		p = p->next;
	}
	add_symbol(symbols, var, prev_mem + 1);
	return(prev_mem + 1);
}
