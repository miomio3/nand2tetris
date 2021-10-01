#include "asm.h"

int ft_isspace(char *p)
{
    if(*p == ' ')
        return(1);
    else
        return(0);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*p;

	i = ft_strlen(s);
	p = malloc(sizeof(char) * (i + 1));
    if(p == NULL)
        return(NULL);
	ft_strcopy(p, s);
	return(p);
}