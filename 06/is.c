#include "asm.h"

int	is_M(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == 'M')
			return(EXIST);
		i++;
	}
	return(NOEXIST);
}

int	is_D(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == 'D')
			return(EXIST);
		i++;
	}
	return(NOEXIST);
}

int	is_A(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == 'A')
			return(EXIST);
		i++;
	}
	return(NOEXIST);
}

int	is_num(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(!(s[i] >= '0' && s[i] <= '9'))
			return(NO);
		i++;
	}
	return(YES);
}