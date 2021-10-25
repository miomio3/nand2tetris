#include "vm.h"

void	open_file(int *fd, char *argv, char *buf)
{
	*fd = open(argv, O_RDONLY);
	if(*fd == -1)
	{
		printf("VMfile couldn't opne.\n");
		free(buf);
		exit(-1);
	}
}

int	open_file2(int *fd, char *file_name)
{
	*fd = open(file_name, O_WRONLY);
	if(*fd == -1)
	{
		printf("ASMfile couldn't opne.\n");
		return(ERROR);
	}
	return(NOERROR);
}

void	read_file(int fd, char *buf, char **vm_code)
{
    *vm_code = NULL;
    while(read(fd, buf, 100) > 0)
    {
        *vm_code = ft_strjoin_free1(*vm_code, buf);
        ft_bzero(buf, 101);
    }
}

void	write2file(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
}
