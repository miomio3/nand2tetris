#include "asm.h"

void    open_file(int *fd, char **argv, char *array)
{
    *fd = open(argv[1], O_RDONLY);
    if(*fd == -1)
    {
        printf("File couldn't opne.\n");
        free(array);
        exit(-1);
    }
}

void    read_file(int fd, char *array, char **assembly)
{
    *assembly = NULL;
    while(read(fd, array, 100) > 0)
    {
        *assembly = ft_strjoin_free1(*assembly, array);
        ft_bzero(array, 101);
    }
}
