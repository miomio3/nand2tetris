#include "compiler.h"

void	verName_compiler(char **code, FILE *fp)
{
	int		i;
	int		i2;
	char	*vername;

	while(**code != ';')
	{
		i = index2space(*code);
		i2 = index2chr(*code, ';') - 1;
		if(i > i2)
			i = i2;
		vername = ft_substr(*code, 0, i + 1);
		fprintf_terminal(fp, "identifier", vername);
		*code = nword(*code, i + 1);
		if(**code == ',')
		{
			fprintf_terminal(fp, "symbol", ",");
			*code = nword(*code, 1);
		}
		free(vername);
	}
	*code = nword(*code, 1);
	fprintf_terminal(fp, "symbol", ";");
	skip_comment_space(code);
}

void	static_compiler(FILE *fp, char **code)
{
	int		i;

	fprintf_nonterminal_begin_nl(fp, "classVerDec");
	fprintf_terminal(fp, "keyword", "static");
	*code = nword(*code, 6);
	fprintf_type(fp, code);
	verName_compiler(code, fp);
	fprintf_nonterminal_end(fp, "classVerDec");
	classVerDec_compiler(code, fp);
}

void	field_compiler(FILE *fp, char **code)
{
	int		i;

	fprintf_nonterminal_begin_nl(fp, "classVerDec");
	fprintf_terminal(fp, "keyword", "field");
	*code = nword(*code, 6);
	fprintf_type(fp, code);
	verName_compiler(code, fp);
	fprintf_nonterminal_end(fp, "classVerDec");
	classVerDec_compiler(code, fp);
}

void	classVerDec_compiler(char **code, FILE *fp)
{
	int		i;
	char	*type;

	if(strncmp2(*code, "static") == 0)
		static_compiler(fp, code);
	else if(strncmp2(*code, "field") == 0)
		field_compiler(fp, code);
}
