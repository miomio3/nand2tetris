#include "compiler.h"

void	letStatement_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "letStatement");
	*code = nword(*code, 3);
	fprintf_identifier2chr2(fp, code, '[', '=');
	if(strncmp2(*code, "[") == 0 )
	{
		fprintf_terminal(fp, "symbol", "[");
		*code = nword(*code, 1);
		expression_compiler(code, fp);
		*code = nword(*code, 1);
		fprintf_terminal(fp, "symbol", "]");
	}
	fprintf_terminal(fp, "symbol", "=");
	*code = nword(*code, 1);
	expression_compiler(code, fp);
	fprintf_nonterminal_end(fp, "letStatement");
}

void	statements_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "statements");
	while(**code != '}')
	{
		if(strncmp2(*code, "let") == 0)
			letStatement_compiler(code, fp);
	//else if(strncmp2(*code, "") == 0)
	//else if(strncmp2(*code, "") == 0)
	//else if(strncmp2(*code, "") == 0)
	//else if(strncmp2(*code, "") == 0)
	}
}