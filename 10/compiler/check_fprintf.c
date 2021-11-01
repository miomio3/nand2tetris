#include "compiler.h"

int	check_fprintf_keywordConstant(FILE *fp, char *term)
{
	if(strcmp(term, "true") == 0)
	{
		fprintf_terminal(fp, "keyword", "true");
		return(1);
	}
	else if(strcmp(term, "false") == 0)
	{
		fprintf_terminal(fp, "keyword", "false");
		return(1);
	}
	else if(strcmp(term, "null") == 0)
	{
		fprintf_terminal(fp, "keyword", "null");
		return(1);
	}
	else if(strcmp(term, "this") == 0)
	{
		fprintf_terminal(fp, "keyword", "this");
		return(1);
	}
	return(0);
}