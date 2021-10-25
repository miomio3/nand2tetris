#include "compiler.h"

void	read_dir(char **argv)
{
	DIR				*dir;
	struct	dirent	*dp;
	char			*buf;
	char			*code;
	int				fd;
	char			*path;

	dir = opendir(argv[1]);
	dp = readdir(dir);
	init_buf(&buf);
	if(dp == NULL)
	{
		printf("DIR couldn't open.\n");
		exit(-1);
	}
	while(dp != NULL)
	{
		path = ft_strjoin(argv[1], dp->d_name);
		if(is_file(path) == TRUE)
		{
			open_jackfile(&fd, path);
			read_jackfile(fd, buf, &code);
			compiler(code, dp->d_name);
			free(code);
		}
		free(path);
		dp = readdir(dir);
	}
	closedir(dir);
}