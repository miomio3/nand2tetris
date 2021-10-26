#include "compiler.h"

void	fprintf_nonterminal_begin(FILE *fp, char *type)
{
	fprintf(fp, "%s", "<");
	fprintf(fp, "%s", type);
	fprintf(fp, "%s", ">");
}

void	fprintf_nonterminal_end(FILE *fp, char *type)
{
	fprintf(fp, "%s", "</");
	fprintf(fp, "%s", type);
	fprintf(fp, "%s", ">\n");
}

void	fprintf_terminal(FILE *fp, char *type, char *word)
{
	fprintf_nonterminal_begin(fp, type);
	fprintf(fp, "%s", word);
	fprintf_nonterminal_end(fp, type);
}

void	fprintf_nonterminal_begin_nl(FILE *fp, char *type)
{
	fprintf_nonterminal_begin(fp, type);
	fprintf(fp, "%s", "\n");
}