#include "asm.h"

void	free_symbols(t_symbols **symbols)
{
	t_symbols	*p;

	while((*symbols))
	{
		p = (*symbols)->next;
		free((*symbols)->symbol);
		free(*symbols);
		*symbols = p;
	}
}

void	free_token(token	**Token)
{
	token	*p;

	while((*Token))
	{
		p = (*Token)->next;
		if((*Token)->save != NULL)
			free((*Token)->save);
		if((*Token)->assign != NULL)
			free((*Token)->assign);
		free((*Token));
		*Token = p;
	}
}