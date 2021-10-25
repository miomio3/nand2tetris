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
	while(**str != 9 && **str != ' ' && **str != '\0' &&  !(**str == '/' && **str == '/')  && **str != '\n' && **str != 13)
	{
		re = re * 10 + **str - '0';
		(*str)++;
	}
	return(re);
}

int	direname_lastindex(char *arg)
{
	int	i;

	i = 0;
	while(arg[i])
	{
		if(arg[i] == '.' && arg[i + 1] == 'v' && arg[i + 2] == 'm')
			break;
		i++;
	}
	while(arg[i] != '/')
		i--;
	return(i - 1);
}

int	direname_0index(char *arg)
{
	int	i;
	int	j;

	i = 0;
	while(arg[i])
	{
		if(arg[i] == '.' && arg[i + 1] == 'v' && arg[i + 2] == 'm')
			break;
		i++;
	}
	j = 0;
	while(arg[i] != '/')
	{
		i--;
		if(arg[i] == '/')
		{
			if(++j == 2)
				break;
			else
				i--;
		}
	}
	return(i + 1);
}



int	filename_lastindex(char *arg)
{
	int	i;

	i = 0;
	while(arg[i])
	{
		if(arg[i] == '.' && arg[i + 1] == 'v' && arg[i + 2] == 'm')
			break;
		i++;
	}
	return(i - 1);
}

int	filename_0index(char *arg)
{
	int	i;
	int	j;

	i = 0;
	while(arg[i])
	{
		if(arg[i] == '.' && arg[i + 1] == 'v' && arg[i + 2] == 'm')
			break;
		i++;
	}
	j = 0;
	while(arg[i] != '/')
		i--;
	return(i + 1);
}

char	*pick_direname(char *arg)
{
	int		start;
	int		last;
	char	*re;

	start = direname_0index(arg);
	last = direname_lastindex(arg);
	re = ft_substr(arg, start, last);
	return(re);
}

char	*pick_filename(char *argv)
{
	int		start;
	int		last;
	char	*re;

	start = filename_0index(argv);
	last = filename_lastindex(argv);
	re = ft_substr(argv, start, last);
	return(re);
}
