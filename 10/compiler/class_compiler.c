#include "compiler.h"

void	subroutineDec_compiler(char **code, FILE *fp)
{
	int		i;
	char	*type;
	char	*subroutineName;

	if(strncmp2(*code, "constructor") == 0)
	{
		fprintf_nonterminal_begin_nl(fp, "subroutineDec");
		fprintf_terminal(fp, "keyword", "constructor");
		*code =nword(*code, 11);
		fprintf_type(fp, code);
		fprintf_identifier2chr(fp, code, '(');
		printf("%s\n", *code);//debug
		fprintf_nonterminal_end(fp, "subroutineDec");
	}
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
	subroutineDec_compiler(&code, fp);
	fprintf_terminal(fp, "symbol", "}");
}

void	class_compiler(char * code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "class");
	fprintf_terminal(fp, "keyword", "class");
	code = nword(code, 5);
	classname_compiler(code, fp);
	fprintf_nonterminal_end(fp, "class");
}
