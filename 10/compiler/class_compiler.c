#include "compiler.h"

void	classname_compiler(char *code, FILE *fp)
{
	int		end;
	char	*classname;

	end = index2chr(code, '{');
	classname = ft_substr(code, 0, end);
	fprintf_terminal(fp, "identifier", classname);
	fprintf_terminal(fp, "symbol", "{");
	code = strchr(code, '{') + 1;
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
