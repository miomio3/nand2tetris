#include "compiler.h"

int	isintegerConstant(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0' && isspace(s[i]) == 0)
		i++;
	if(isdigit(s[i - 1]) == 0)
		return(0);
	return(1);
}