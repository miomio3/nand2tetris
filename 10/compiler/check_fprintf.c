#include "compiler.h"

int	check_fprintf_keywordConstant(FILE *fp, char **code)
{
	if(strncmp2(*code, "true") == 0)
	{
		fprintf_terminal(fp, "keyword", "true");
		*code = nword(*code, 4);
		return(1);
	}
	else if(strncmp2(*code, "false") == 0)
	{
		fprintf_terminal(fp, "keyword", "false");
		*code = nword(*code, 5);
		return(1);
	}
	else if(strncmp2(*code, "null") == 0)
	{
		fprintf_terminal(fp, "keyword", "null");
		*code = nword(*code, 4);
		return(1);
	}
	else if(strncmp2(*code, "this") == 0)
	{
		fprintf_terminal(fp, "keyword", "this");
		*code = nword(*code, 4);
		return(1);
	}
	return(0);
}