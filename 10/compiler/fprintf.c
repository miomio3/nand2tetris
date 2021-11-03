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
	*code = nword(*code, i);
	free(identifier);
}

void	fprintf_identifier2chr2(FILE *fp, char **code, char chr, char chr2)
{
	int		i;
	int		i2;
	char	*identifier;

	i = index2chr(*code, chr);
	i2 = index2chr(*code, chr2);
	if(i2 < i)
		i = i2;
	identifier = ft_substr(*code, 0, i);
	fprintf_terminal(fp, "identifier", identifier);
	*code = nword(*code, i);
	free(identifier);
}

void	fprintf_integerRecursion(FILE *fp, char **code)
{
	char	c;

	if(isdigit(**code) != 0)
	{
		c = **code;
		*code = nword(*code, 1);
		fprintf_integerRecursion(fp, code);
		fprintf(fp, "%c", c);
	}
	else
		return;
}

void	fprintf_integerConstant(FILE *fp, char **code)
{
	fprintf_nonterminal_begin(fp, "integerConstant");
	fprintf_integerRecursion(fp, code);
	fprintf_nonterminal_end(fp, "integerConstant");
}

void	fprintf2dilimiter(FILE *fp, char **code)
{
	int		i;
	char	*str;

	i = 0;
	while(isdilimiter(*(*code + i)) != 1)
		i++;
	str = ft_substr(*code, 0, i);
	fprintf(fp, "%s", str);
	*code = nword(*code, i);
	free(str);
}
