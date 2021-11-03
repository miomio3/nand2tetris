#include "compiler.h"

void	letStatement_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "letStatement");
	fprintf_terminal(fp, "keyword", "let");
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
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ";");
	skip_comment_space(code);
	fprintf_nonterminal_end(fp, "letStatement");
}

void	ifStatement_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "ifStatement");
	fprintf_terminal(fp, "keyword", "if");
	*code = nword(*code, 2);
	fprintf_terminal(fp, "symbol", "(");
	*code = nword(*code, 1);
	expression_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ")");
	fprintf_terminal(fp, "symbol", "{");
	*code = nword(*code, 1);
	statements_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", "}");
	skip_comment_space(code);
	if(strncmp2(*code, "else") == 0)
	{
		fprintf_terminal(fp, "keyword", "else");
		*code = nword(*code, 4);
		fprintf_terminal(fp, "symbol", "{");
		*code = nword(*code, 1);
		statements_compiler(code, fp);
		*code = nword(*code, 1);
		fprintf_terminal(fp, "symbol", "}");
		skip_comment_space(code);
	}
	fprintf_nonterminal_end(fp, "ifStatement");
}

void	whileStatement_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "whileStatement");
	fprintf_terminal(fp, "keyword", "while");
	*code = nword(*code, 5);
	fprintf_terminal(fp, "symbol", "(");
	*code = nword(*code, 1);
	expression_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ")");
	fprintf_terminal(fp, "symbol", "{");
	*code = nword(*code, 1);
	statements_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", "}");
	fprintf_nonterminal_end(fp, "whileStatement");
	skip_comment_space(code);
}

void	doStatement_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "doStatement");
	fprintf_terminal(fp, "keyword", "do");
	*code = nword(*code, 2);
	subroutineCall_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ";");
	fprintf_nonterminal_end(fp, "doStatement");
	skip_comment_space(code);
}

void	returnStatement_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "returnStatement");
	fprintf_terminal(fp, "keyword", "return");
	*code = nword(*code, 6);
	if(**code != ';')
		expression_compiler(code, fp);
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ";");
	fprintf_nonterminal_end(fp, "returnStatement");
	skip_comment_space(code);
}

void	statements_compiler(char **code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "statements");
	while(**code != '}')
	{
		if(strncmp2(*code, "let") == 0)
			letStatement_compiler(code, fp);
		else if(strncmp2(*code, "if") == 0)
			ifStatement_compiler(code, fp);
		else if(strncmp2(*code, "while") == 0)
			whileStatement_compiler(code, fp);
		else if(strncmp2(*code, "do") == 0)
			doStatement_compiler(code, fp);
		else if(strncmp2(*code, "return") == 0)
			returnStatement_compiler(code, fp);
	}
	fprintf_nonterminal_end(fp, "statements");
}