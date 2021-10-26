#include "compiler.h"

void	class_compiler(char * code, FILE *fp)
{
	fprintf_nonterminal_begin_nl(fp, "class");
	fprintf_terminal(fp, "keyword", "class");
	code = nword(code, 5);
	//classname_compiler(code, fp);
	fprintf_nonterminal_end(fp, "class");
}
