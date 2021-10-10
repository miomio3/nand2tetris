#include "vm.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i])
	{
		if(s1[i] != s2[i])
			return(FALSE);
		i++;
	}
	if(s2[i] != '\0')
		return(FALSE);
	return(TRUE);
}

char	*nl(char *p)
{
    while(*p != '\n' && *p != '\0')
        p++;
    if(*p == '\n')
		p++;
    return(p);
}