#include "compiler.h"

int	main(void)
{
	char	c;
	FILE *fp;

	c = '0';
	fp = fopen("test.jack", "w");
	fprintf(fp, "%c", c);
	fclose(fp);
}