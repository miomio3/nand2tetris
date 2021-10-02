#include "asm.h"

char	*pick_var(char *s)
{
	char	*p;
	char	*re;
	int		len;
	int		i;

	p = s;
	len = 0;
	while(!(p[len] == '/' && p[len + 1] == '/') && p[len] != ' ' && p[len] != '\n' && p[len] != 13)
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

int	convert2num(char *s)
{
	int	re;
	int	len;
	int	i;

	len = ft_strlen(s);
	i = 0;
	re = 0;
	while(i < len)
	{
		re = 10 * re + s[i] - '0';
		i++;
	}
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
	(*p)->save = NULL;
	(*p)->assign = NULL;
	var = pick_var(s + 1);
	if(is_num(var) == YES)
		(*p)->memory = convert2num(var);
	else
		(*p)->memory = search_symbol(symbols, var);
	(*p)->order = count_Token(*Token) - 2;
	free(var);
}
