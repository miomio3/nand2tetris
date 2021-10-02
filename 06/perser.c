#include "asm.h"

char	*nl(char *p)
{
    while(*p != '\n')
        p++;
    p++;
    return(p);
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
        else
		{
			add_Ctoken();
			p = nl(p);
			continue;
		}
    }
	while(symbols->next)//debug
	{
		printf("%d\n", symbols->memory);
		printf("%s\n", symbols->symbol);
		symbols = symbols->next;
	}
	printf("%d\n", symbols->memory);
	printf("%s\n", symbols->symbol);
	return(Token);
}