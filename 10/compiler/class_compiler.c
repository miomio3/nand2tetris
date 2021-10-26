#include "compiler.h"

void	classVerDec_compiler(char **code, FILE *fp)
{
	int		i;
	char	*type;

	if(strncmp2(*code, "static") == 0)
	{
		fprintf_nonterminal_begin_nl(fp, "classVerDec");
		fprintf_terminal(fp, "keyword", "static");
		*code = nword(*code, 6);
		i = index2space(*code);
		type = ft_substr(*code, 0, i + 1);
		fprintf_terminal(fp, "type", type);
		*code = nword(*code, i + 1);
		//verName_compiler
		free(type);
		fprintf_nonterminal_end(fp, "classVerDec");
	}
	/* else if(strncmp2(*code, "static") == 0)
	{

	} */
}

void	classname_compiler(char *code, FILE *fp)
{
	int		end;
	char	*classname;

	end = index2chr(code, '{');
	classname = ft_substr(code, 0, end);
	fprintf_terminal(fp, "identifier", classname);
	fprintf_terminal(fp, "symbol", "{");
	code = strchr(code, '{') + 1;
	skip_comment_space(&code);
	classVerDec_compiler(&code , fp);
	//subroutineDec_compiler(&code, fp);
}

void	class_compiler(char * code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "class");
	fprintf_terminal(fp, "keyword", "class");
	code = nword(code, 5);
	classname_compiler(code, fp);
	fprintf_nonterminal_end(fp, "class");
}
