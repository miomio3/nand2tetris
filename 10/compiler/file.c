#include "compiler.h"

void	open_jackfile(int *fd, char *argv)
{
	*fd = open(argv, O_RDONLY);
	if(*fd == -1)
	{
		printf("JACKfile couldn't opne.\n");
		exit(-1);
	}
}

void	open_vmfile(int *fd, char *filename)
{
	*fd = open(filename, O_WRONLY);
	if(*fd == -1)
	{
		printf("VMfile couldn't opne.\n");
		exit(-1);
	}
}

void	read_jackfile(int fd, char *buf, char **code)
{
	*code = NULL;
    while(read(fd, buf, 100) > 0)
    {
        *code = ft_strjoin_free1(*code, buf);
        ft_bzero(buf, 100);
    }
}

void	read_files(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*buf;
	char	*code;

	init_buf(&buf);
	i = 1;
    while(i < argc)
    {
        open_jackfile(&fd, argv[i]);
        read_jackfile(fd, buf, &code);
		compiler(code, argv[i]);
		free(code);
        i++;
    }
}
