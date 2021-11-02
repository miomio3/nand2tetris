#include "compiler.h"

int	isintegerConstant(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0' && s[i] != ')')
	{
		if(isdigit(s[i]) == 0)
			return(0);
		i++;
	}
	return(1);
}

int	isunaryOp(char c)
{
	if(c == '-' || c == '~')
		return(1);
	return(0);
}