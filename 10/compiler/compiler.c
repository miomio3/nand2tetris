#include "compiler.h"

void	compiler(char *code, char *J_filename)
{
	FILE	*fp;
	char	*V_filename;

	V_filename = create_V_filename(J_filename);
	fp = fopen(V_filename, "w");
	skip_comment_space(&code);
	if(strncmp2(code, "class") == 0)
		class_compiler(code, fp);
	free(V_filename);
	fclose(fp);
}