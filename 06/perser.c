#include "asm.h"

char	*nl(char *p)
{
    while(*p != '\n' && *p != '\0')
        p++;
    if(*p == '\n')
		p++;
    return(p);
}

int	is_equal2nl(char *s)
{
	int	i;

	i = 0;
	while(!(s[i] == '/' && s[i + 1] == '/') && s[i] != ' ' && s[i] != '\n')
	{
		if(s[i] == '=')
			return(EXIST);
		i++;
	}
	return(NOEXIST);
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
        if((p[0] == '/' && p[1] == '/') || p[0] == '\n' || p[0] == 13)
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
        else if(is_equal2nl(p) == EXIST)
		{
			add_Ctoken(p, &Token);
			p = nl(p);
			continue;
		}
		else
		{
			add_Jtoken(p, &Token);
			p = nl(p);
			continue;
		}
    }
	return(Token);
}