#include "compiler.h"

void	unaryOp_compiler(char **code, FILE *fp)
{
	if(**code == '-')
	{
		fprintf_terminal(fp, "symbol", "-");
		*code = nword(*code, 1);
	}
	else if(**code == '~')
	{
		fprintf_terminal(fp, "symbol", "~");
		*code = nword(*code, 1);
	}
	term_compiler(code, fp);
}

void	term_compiler(char **code, FILE *fp)
{

	fprintf_nonterminal_begin_nl(fp, "term");
	if(check_fprintf_keywordConstant(fp, code) == 1)
		;
	else if(isintegerConstant(*code) == 1)
		fprintf_integerConstant(fp, code);
	else if(**code == '(')
	{
		fprintf_terminal(fp, "symbol", "(");
		*code = nword(*code, 1);
		expression_compiler(code, fp);
		*code = nword(*code, 1);
		fprintf_terminal(fp, "symbol", ")");
	}
	else if(isunaryOp(**code) == 1)
		unaryOp_compiler(code, fp);
	fprintf_nonterminal_end(fp, "term");
}

void	expression_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "expression");
	term_compiler(code, fp);
	//fprintf_identifier2chr2(fp, code, '[', ')');//op,subroutinecallへの対応も必要
	fprintf_nonterminal_end(fp, "expression");
}
