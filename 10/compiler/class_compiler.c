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
}

void	static_compiler(FILE *fp, char **code)
{
	int		i;
	char	*type;

	fprintf_terminal(fp, "keyword", "static");
	*code = nword(*code, 6);
	i = index2space(*code);
	type = ft_substr(*code, 0, i + 1);
	fprintf_terminal(fp, "type", type);
	*code = nword(*code, i + 1);
	verName_compiler(code, fp);
	free(type);
	if(strncmp2(*code, "field") == 0)
		field_compiler(fp, code);
}

void	field_compiler(FILE *fp, char **code)
{
	int		i;
	char	*type;

	fprintf_terminal(fp, "keyword", "field");
	*code = nword(*code, 6);
	i = index2space(*code);
	type = ft_substr(*code, 0, i + 1);
	fprintf_terminal(fp, "type", type);
	*code = nword(*code, i + 1);
	verName_compiler(code, fp);
	free(type);
	if(strncmp2(*code, "field") == 0)
		static_compiler(fp, code);
}

void	classVerDec_compiler(char **code, FILE *fp)
{
	int		i;
	char	*type;

	if(strncmp2(*code, "static") == 0)
	{
		fprintf_nonterminal_begin_nl(fp, "classVerDec");
		static_compiler(fp, code);
		fprintf_nonterminal_end(fp, "classVerDec");
	}
	else if(strncmp2(*code, "field") == 0)
	{
		fprintf_nonterminal_begin_nl(fp, "classVerDec");
		field_compiler(fp, code);
		fprintf_nonterminal_end(fp, "classVerDec");
	}
}

void	classname_compiler(char *code, FILE *fp)
{
	int		end;
	char	*classname;

	end = index2chr(code, '{');
	classname = ft_substr(code, 0, end);
	fprintf_terminal(fp, "identifier", classname);
	fprintf_terminal(fp, "symbol", "{");
	code = strchr(code, '{') + 1;
	skip_comment_space(&code);
	classVerDec_compiler(&code , fp);
	//subroutineDec_compiler(&code, fp);
	fprintf_terminal(fp, "symbol", "}");
}

void	class_compiler(char * code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "class");
	fprintf_terminal(fp, "keyword", "class");
	code = nword(code, 5);
	classname_compiler(code, fp);
	fprintf_nonterminal_end(fp, "class");
}
