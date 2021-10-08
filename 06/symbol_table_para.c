#include "asm.h"

t_symbols	**addfront_symbol(t_symbols **symbols, char *s, int memory)
{
	t_symbols	*new;

	new = malloc(sizeof(t_symbols) * 1);
	new->memory = memory;
	new->symbol = ft_strdup(s);
	new->next = *symbols;
	*symbols = new;
	return(symbols);
}

char	*ft_substr2para(char *p)
{
	int		len;
	char	*re;
	int		j;

	len = 0;
	while(p[len] != ')')
		len++;
	re = malloc(sizeof(char) * (len + 1));
	j = 0;
	while(len--)
	{
		re[j] = p[j];
		j++;
	}
	re[j] = '\0';
	return(re);
}

void	add_para_symbol(t_symbols **symbols, char *p, int memory)
{
	char	*s;

	s = ft_substr2para(p + 1);
	symbols = addfront_symbol(symbols, s, memory);
	free(s);
}

void		add_para(t_symbols **symbols, char *assembly)
{
	char	*p;
	int		i;

	p = assembly;
	i = 0;
	while(*p)
	{
		while(ft_isspace(p))
            p++;
		if(*p == '(')
		{
			add_para_symbol(symbols, p, i);
			p = nl(p);
			continue;
		}
		else if((p[0] == '/' && p[1] == '/') || p[0] == '\n' || p[0] == 13)
		{
			p = nl(p);
			continue;
		}
		else
		{
			i++;
			p = nl(p);
			continue;
		}
	}
}
