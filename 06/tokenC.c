#include "asm.h"

char	*ft_substr_2equal(char *s)
{
	char	*re;
	char	*p;
	int		len;
	int		i;

	p = s;
	len = 0;
	while(p[len] != '=')
		len++;
	re = malloc(sizeof(char) * (len + 1));
	i = 0;
	while(p[i] != '=')
	{
		re[i] = p[i];
		i++;
	}
	re[i] = '\0';
	return(re);
}

char	*ft_substr_equal2nl(char *s)
{
	char	*re;
	char	*p;
	int		len;
	int		i;

	while(*s != '=')
		s++;
	s++;
	p = s;
	len = 0;
	while(!(p[len] == '/' && p[len + 1] == '/') && p[len] != ' ' && p[len] != '\n')
		len++;
	re = malloc(sizeof(char) * (len + 1));
	i = 0;
	while(!(p[i] == '/' && p[i + 1] == '/') && p[i] != ' ' && p[i] != '\n')
	{
		re[i] = p[i];
		i++;
	}
	re[i] = '\0';
	return(re);
}

void	add_Ctoken(char *s, token **Token)
{
	token	**p;

	p = Token;
	while(*p != NULL)
		p = &((*p)->next);
	*p = malloc(sizeof(token) * 1);
	(*p)->next = NULL;
	(*p)->type = C;
	(*p)->save = ft_substr_2equal(s);
	(*p)->assign = ft_substr_equal2nl(s);
	(*p)->order = count_Token(*Token) - 2;//今のトークンも含めた分をひく
}
