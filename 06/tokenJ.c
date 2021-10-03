#include "asm.h"

void	add_Jtoken(char *s, token **Token)
{
	token	**p;
	int		i;

	p = Token;
	while(*p != NULL)
		p = &((*p)->next);
	*p = malloc(sizeof(token) * 1);
	(*p)->next = NULL;
	(*p)->type = J;
	(*p)->save = malloc(sizeof(char) * 2);
	(*p)->save[0] = s[0];
	(*p)->save[1] = '\0';
	s = s + 2;
	(*p)->assign = malloc(sizeof(char) * 4);
	i = 0;
	while(!(s[i] == '/' && s[i + 1] == '/') && s[i] != ' ' && s[i] != '\n' && s[i] != 13)
	{
		(*p)->assign[i] = s[i];
		i++;
	}
	(*p)->assign[i] = '\0';
	(*p)->order = count_Token(*Token) - 2;
}