#include "asm.h"

void	open_file(int *fd, char **argv, char *array)
{
	*fd = open(argv[1], O_RDONLY);
	if(*fd == -1)
	{
		printf("File couldn't opne.\n");
		free(array);
		exit(-1);
	}
}

int	open_file2(int *fd, char *file_name)
{
	*fd = open(file_name, O_WRONLY);
	if(*fd == -1)
	{
		printf("File couldn't opne.\n");
		return(ERROR);
	}
	return(NOERROR);
}

void	read_file(int fd, char *array, char **assembly)
{
    *assembly = NULL;
    while(read(fd, array, 100) > 0)
    {
        *assembly = ft_strjoin_free1(*assembly, array);
        ft_bzero(array, 101);
    }
}

void	write2file(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
}
