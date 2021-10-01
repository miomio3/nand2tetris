#include "asm.h"

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
	(*p)->order = count_Token(*Token) - 2;
}
