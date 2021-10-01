#include "asm.h"

char    *nl(char *p)
{
    while(*p != '\n')
        p++;
    p++;
    return(p);
}

int	count_Token(token *Token)
{
	int		i;
	token	*p;

	p = Token;
	i = 0;
	while(p != NULL)
	{
		p = p->next;
		i++;
	}
	return(i + 1);
}

void    perser(char *assembly, t_symbols *symbols)
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
		/* else if(*p == '@')
		{
			add_Atoken();
			p = nl(p);
			continue;
		}
        else
		{
			add_Ctoken();
			p = nl(p);
			continue;
		} */
    }
}