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
/* 
char	*skip2chr(char *s, char c)
{
	while(isspace(*s) != 0 || *s != c)
		s++;
	return(s);
} */
/* 
char	*skip_spaces(char *s)
{
	while(isspace(*s) != 0)
		s++;
	return(s);
}
 */