#include "compiler.h"

int	isop(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/' || \
	c == '&' || c == '|' || c == '<' || c == '>' || c == '=')
		return(1);
	return(0);
}

int	isdilimiter(char c)
{
	if(c == '\0' || c == ')' || c == ']' || c == ';' \
	|| c == ',' || isspace(c) != 0 )
	return(1);
	return(0);
}

int	isintegerConstant(char *s)
{
	int	i;

	i = 0;
	while(isdilimiter(s[i]) != 1)
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

int	isvarPare(char *s)
{
	int	i;

	i = 0;
	while(isdilimiter(s[i]) != 1)
	{
		if(s[i] == '[')
			return(1);
		i++;
	}
	return(0);
}

int	issubroutineCall(char *s)
{
	int	i;

	i = 0;
	while(isdilimiter(s[i]) != 1)
	{
		if(s[i] == '(')
			return(1);
		i++;
	}
	return(0);
}