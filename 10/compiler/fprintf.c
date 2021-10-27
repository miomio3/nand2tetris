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

void	fprintf_type(FILE *fp, char **code)
{
	int		i;
	char	*type;

	i = index2space(*code);
	type = ft_substr(*code, 0, i + 1);
	if(strncmp2(type, "int") == 0)
		fprintf_terminal(fp, "keyword", "int");
	else if(strncmp2(type, "char") == 0)
		fprintf_terminal(fp, "keyword", "char");
	else if(strncmp2(type, "boolean") == 0)
		fprintf_terminal(fp, "keyword", "boolean");
	else if(strncmp2(type, "void") == 0)
		fprintf_terminal(fp, "keyword", "void");
	else
		fprintf_terminal(fp, "identifier", type);
	*code = nword(*code, i + 1);
	free(type);
}

void	fprintf_identifier2chr(FILE *fp, char **code, char chr)
{
	int		i;
	char	*identifier;

	i = index2chr(*code, chr);
	identifier = ft_substr(*code, 0, i);
	fprintf_terminal(fp, "identifier", identifier);
	*code = nword(*code, i + 1);
	free(identifier);
}