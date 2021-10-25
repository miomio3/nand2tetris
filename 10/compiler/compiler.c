#include "compiler.h"

void	compiler(char *code, char *J_filename)
{
	FILE	*fp;
	char	*V_filename;

	V_filename = create_V_filename(J_filename);
	printf("%s\n", V_filename);
	fp = fopen(V_filename, "w");
	free(V_filename);
}