#include "compiler.h"

void	skip_comments(char **code)
{
	if(**code == '/' && *(*code + 1) == '/')
		*code = nl(*code);
	else if(**code == '/' && *(*code + 1) == '*')
		*code = nnest(*code);
}

int	iscomment(char *s)
{
	if(*s == '/' && *(s + 1) == '/')
		return(1);
	else if(*s == '/' && *(s + 1) == '*')
		return(1);
	return(0);
}

void	skip_comment_space(char **code)
{
	while(isspace(**code) != 0 || iscomment(*code) != 0)
	{
		while(isspace(**code) != 0)
			(*code)++;
		skip_comments(code);
	}
}

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
	while(isspace(*(s + n)) != 0)
		n++;
	return(s + n);
}
