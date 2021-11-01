#include "compiler.h"

void	term_compiler(char **code, FILE *fp)
{
	char	*term;

	term = pick_term(code);
	if(check_fprintf_keywordConstant(fp, term) == 1)
		return;
	else if(isintegerConstant(term) == 1)
		fprintf_integerConstant(fp, code);
	else if(**code == '(')
	{
		fprintf_terminal(fp, "symbol", "(");
		*code = nword(*code, 1);
		expression_compiler(code, fp);
	}
}

void	expression_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "expression");
	term_compiler(code, fp);
	//fprintf_identifier2chr2(fp, code, '[', ')');//op,subroutinecallへの対応も必要
	fprintf_nonterminal_end(fp, "expression");
}
