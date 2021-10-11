#include "vm.h"

char	*pick2space(char *s)
{
	char	*p;
	char	*re;
	int		len;
	int		i;

	p = s;
	len = 0;
	while( p[len] != ' ' && p[len] != '\0' && !(p[len] == '/' && p[len + 1] == '/') && p[len] != '\n' && p[len] != 13)
		len++;
	re = malloc(sizeof(char) * (len + 1));
	i = 0;
	while(len--)
	{
		re[i] = s[i];
		i++;
	}
	re[i] = '\0';
	return(re);
}

int	pick2space_num(char **str)
{
	int		re;

	re = 0;
	while(**str != ' ' && **str != '\0' &&  !(**str == '/' && **str == '/')  && **str != '\n' && **str != 13)
	{
		re = re * 10 + **str - '0';
		(*str)++;
	}
	return(re);
}

int	last_slash_index(char *p)
{
	int	last;
	int	i;

	last = 0;
	i = 0;
	while(p[i])
	{
		if(p[i] == '/')
			last = i + 1;
		i++;
	}
	return(last);
}

char	*pick_filename(char *arg)
{
	int		i;
	int		start;
	char	*re;

	i = 0;
	start = last_slash_index(arg);
	while(arg[i])
	{
		if(arg[i] == '.' && arg[i + 1] == 'v' && arg[i + 2] == 'm')
		{
			re = ft_substr(arg, start, i);
			break;
		}
		i++;
	}
	return(re);
}
