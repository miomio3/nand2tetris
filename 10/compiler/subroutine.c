#include "compiler.h"

void	varDec_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "varDec");
	fprintf_terminal(fp, "keyword", "var");
	*code = nword(*code, 3);
	fprintf_type(fp, code);
	while(**code != ';')
	{
		fprintf_identifier2chr2(fp, code, ',', ';');
		if(**code == ',')
		{
			fprintf_terminal(fp, "symbol", ",");
			*code = nword(*code, 1);
		}
	}
	*code = nword(*code, 1);
	skip_comment_space(code);
	fprintf_terminal(fp, "symbol", ";");
	fprintf_nonterminal_end(fp, "varDec");
}

void	subroutineBody_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "subroutineBody");
	fprintf_terminal(fp, "symbol", "{");
	*code = nword(*code, 1);
	while(strncmp2(*code, "var") == 0)
			varDec_compiler(code, fp);
	while(**code != '}')
			statement_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", "}");
	fprintf_nonterminal_begin_nl(fp, "subroutineBody");
	skip_comment_space(code);
}

void	parameterList_compiler(char **code, FILE *fp)
{
	int		i;
	int		i2;

	fprintf_terminal(fp, "symbol", "(");
	*code = nword(*code, 1);
	fprintf_nonterminal_begin_nl(fp, "parameterList");
	while(**code != ')')
	{
		fprintf_type(fp, code);
		fprintf_identifier2chr2(fp, code, ',', ')');
		if(**code == ',')
		{
			fprintf_terminal(fp, "symbol", ",");
			*code = nword(*code, 1);
		}
	}
	fprintf_nonterminal_end(fp, "parameterList");
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ")");
}

void	subroutineDec_compiler(char **code, FILE *fp)
{
	int		i;
	char	*type;
	char	*subroutineName;

	if(strncmp2(*code, "constructor") == 0)
	{
		fprintf_nonterminal_begin_nl(fp, "subroutineDec");
		fprintf_terminal(fp, "keyword", "constructor");
		*code = nword(*code, 11);
		fprintf_type(fp, code);
		fprintf_identifier2chr(fp, code, '(');
		parameterList_compiler(code, fp);
		subroutineBody_compiler(code, fp);
		fprintf_nonterminal_end(fp, "subroutineDec");
		subroutineDec_compiler(code, fp);
	}
}
