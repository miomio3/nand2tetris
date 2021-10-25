#include "compiler.h"

int	main(int argc, char **argv)
{
	DIR				*dir;
	struct	dirent	*dp;

	dir = opendir(argv[1]);
	dp = readdir(dir);
	while(dp != NULL)
	{
		printf("%s\n", dp->d_name);
		dp = readdir(dir);
	}
	closedir(dir);
	return(0);
}