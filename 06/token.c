#include "asm.h"

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
