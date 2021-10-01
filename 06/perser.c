#include "asm.h"

char	*nl(char *p)
{
    while(*p != '\n')
        p++;
    p++;
    return(p);
}

char	*pick_var(char *s)
{
	char	*p;
	char	*re;
	int		len;
	int		i;

	p = s;
	len = 0;
	while(!(p[len] == '/' && p[len + 1] == '/') && p[len] != ' ' && p[len] != '\n')
		len++;
	re = malloc(sizeof(char) * (len + 1));
	i = 0;
	while(len--)
	{
		re[i] = s[i];
		i++;
	}
	re[i] = '\0';
	return(re);
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

void	add_Atoken(t_symbols **symbols, char *s, token **Token)
{
	token	**p;
	char	*var;

	p = Token;
	while(*p != NULL)
		p = &((*p)->next);
	*p = malloc(sizeof(token) * 1);
	(*p)->next = NULL;
	(*p)->type = A;
	var = pick_var(s + 1);
	(*p)->memory = search_symbol(symbols, var);
	(*p)->order = count_Token(*Token) - 1;
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
			while(symbols->next)
				symbols = symbols->next;
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