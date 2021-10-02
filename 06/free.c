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

void	free_token(t_token	**Token)
{
	t_token	*p;

	while((*token))
	{
		p = (*token)->next;
		if((*token)->save != NULL)
			free((*token)->save);
		if((*token)->assign != NULL)
			free((*token)->assign);
		free((*token));
		*token = p;
	}
}