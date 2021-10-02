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

t_symbols    *init_symbol_table(void)
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
	return(head);
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

void	addfront_symbol(t_symbols **symbols, char *s, int memory)
{
	t_symbols	*new;

	new = malloc(sizeof(t_symbols) * 1);
	new->memory = memory;
	new->symbol = ft_strdup(s);
	new->next = *symbols;
	*symbols = new;
}

void	add_para_symbol(t_symbols **symbols, char *p, token *Token)
{
	int		memory;
	char	*s;

	memory = count_Token(Token);
	s = ft_substr2para(p + 1);
	addfront_symbol(symbols, s, memory);
	free(s);
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
