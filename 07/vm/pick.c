#include "vm.h"

char	*pick_first(char **str)
{
	char	*re;
	int		i;
	int		len;

	len = 0;
	while(*str[len] != ' ' &&  *str[len] !='\0' && !(*str[len] == '/' && *str[len+1] == '/') && *str[len] != '\n' && *str[len] != 13)
		len++;
	re = malloc(sizeof(char) * (len + 1));
	i = 0;
	while(**str != ' ' && **str !='\0' &&  !(**str == '/' && **str == '/')  && **str != '\n' && **str != 13)
	{
		re[i] = **str;
		i++;
		(*str)++;
	}
	re[i] = '\0';
	return(re);
}
