#include "asm.h"

void    init_array(char **array)
{
    *array = malloc(sizeof(char) * 101);
    if(*array == NULL)
        exit(-1);
    ft_bzero(*array, 101);
}

int main(int argc, char **argv)
{
    char    *array;
    char    *assembly;
    int     fd;

    init_array(&array);
    open_file(&fd, argv, array);
    read_file(fd, array, &assembly);
    assembler();
    //printf("%s", assembly);//debug
    safe_free(array);
    safe_free(assembly);
    return(0);
}