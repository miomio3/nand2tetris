#include "compiler.h"

char	*nl(char *p)
{
    while(*p != '\n' && *p != '\0')
        p++;
    if(*p == '\n')
		p++;
    return(p);
}

char	*nnest(char *s)
{
	while(!(*s == '*' && *(s + 1) == '/'))
		s++;
	return(s + 2);
}

char	*nword(char *s, int n)
{
	while(isspace(*(s + n)) != 0 && *(s + n) != '\0')
		n++;
	return(s + n);
}

int	index2chr(char *s, char c)
{
	int	i;

	i = 0;
	while(isspace(s[i]) == 0 && s[i] != c)
		i++;
	return(i);
}

int	index2space(char *s)
{
	int	i;

	i = 0;
	while(isspace(s[i]) == 0)
		i++;
	return(i - 1);
}