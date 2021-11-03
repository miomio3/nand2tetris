#include "compiler.h"

void	op_compiler(char **code, FILE *fp)
{
	if(strncmp2(*code, "+") == 0)
		fprintf_terminal(fp, "symbol", "+");
	else if(strncmp2(*code, "-") == 0)
		fprintf_terminal(fp, "symbol", "-");
	else if(strncmp2(*code, "&") == 0)
		fprintf_terminal(fp, "symbol", "&");
	else if(strncmp2(*code, "*") == 0)
		fprintf_terminal(fp, "symbol", "*");
	else if(strncmp2(*code, "/") == 0)
		fprintf_terminal(fp, "symbol", "/");
	else if(strncmp2(*code, "|") == 0)
		fprintf_terminal(fp, "symbol", "|");
	else if(strncmp2(*code, "<") == 0)
		fprintf_terminal(fp, "symbol", "<");
	else if(strncmp2(*code, ">") == 0)
		fprintf_terminal(fp, "symbol", ">");
	else if(strncmp2(*code, "=") == 0)
		fprintf_terminal(fp, "symbol", "=");
	*code = nword(*code, 1);
}

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

void	varPare_compiler(char **code, FILE *fp)
{
	fprintf_identifier2chr(fp, code, '[');
	fprintf_terminal(fp, "symbol", "[");
	*code = nword(*code, 1);
	expression_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", "]");
}

void	expressionList_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "expressionList");
	while(**code != ')')
	{
		expression_compiler(code, fp);
		if(**code == ',')
		{
			fprintf_terminal(fp, "symbol", ",");
			*code = nword(*code, 1);
		}
	}
	fprintf_nonterminal_end(fp, "expressionList");
}

void	subroutineCall_compiler(char **code, FILE *fp)
{
	fprintf_identifier2chr2(fp, code, '.', '(');
	if(**code == '.')
	{
		fprintf_terminal(fp, "symbol", ".");
		*code = nword(*code, 1);
		fprintf_identifier2chr(fp, code, '(');
	}
	fprintf_terminal(fp, "symbol", "(");
	*code = nword(*code, 1);
	expressionList_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ")");
}

void	identifier_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin(fp, "identifier");
	fprintf2dilimiter(fp, code);
	fprintf_nonterminal_end(fp, "identifier");
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
	else if(isvarPare(*code) == 1)
		varPare_compiler(code, fp);
	else if(issubroutineCall(*code) == 1)
		subroutineCall_compiler(code, fp);
	else
		identifier_compiler(code, fp);
	fprintf_nonterminal_end(fp, "term");
}

void	expression_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "expression");
	term_compiler(code, fp);
	while(isop(**code) == 1)
	{
		op_compiler(code, fp);
		term_compiler(code, fp);
	}
	fprintf_nonterminal_end(fp, "expression");
}
