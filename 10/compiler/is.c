#include "compiler.h"

int	isintegerConstant(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0')
	{
		if(isdigit(s[i]) == 0)
			return(0);
		i++;
	}
	return(1);
}