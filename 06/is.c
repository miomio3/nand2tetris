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