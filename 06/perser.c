#include "asm.h"

char	*nl(char *p)
{
    while(*p != '\n')
        p++;
    p++;
    return(p);
}

int	search_symbol(t_symbols **symbols, char *var)
{
	t_symbols	*p;
	int			prev_mem;

	p = *symbols;
	while(p != NULL)
	{
		if(p->symbol == var)
			return(p->memory);
		prev_mem = p->memory;
		p = p->next;
	}
	add_symbol(symbols, var, prev_mem + 1);
	return(prev_mem + 1);
}

token	*perser(char *assembly, t_symbols *symbols)
{
    char    *p;
	token	*Token;

    p = assembly;
	Token = NULL;
    while(*p)
    {
        while(ft_isspace(p))
            p++;
        if((*p == '/' && *p == '/') || *p == '\n')
        {
            p = nl(p);
            continue;
        }
		else if(*p == '(')
		{
			add_para_symbol(&symbols, p, Token);
			p = nl(p);
			continue;
		}
		else if(*p == '@')
		{
			add_Atoken(&symbols, p, &Token);
			p = nl(p);
			continue;
		}
        /*else
		{
			add_Ctoken();
			p = nl(p);
			continue;
		} */
    }
	return(Token);
}