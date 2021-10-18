#include "vm.h"

void    init_buf(char **array)
{
    *array = malloc(sizeof(char) * 101);
    if(*array == NULL)
        exit(-1);
    ft_bzero(*array, 101);
}

int	main(int argc, char **argv)
{
	char    *buf;
    char    *vm_code;
	char	*direname;
    char    *filename;
    int     fd;
    int     asmfd;
    int     i;

    if(open_file2(&asmfd, "vm.asm") == ERROR)
		return(0);
    direname = pick_direname(argv[1]);
    init_buf(&buf);
    i = 1;
    while(i < argc)
    {
        filename = pick_filename(argv[i]);
        open_file(&fd, argv[i], buf);
        read_file(fd, buf, &vm_code);
	    vm(vm_code, direname, filename, asmfd);
        ft_bzero(vm_code, ft_strlen(vm_code));
        free(filename);
        i++;
    }
	close(fd);
    close(asmfd);
    safe_free(buf);
    safe_free(vm_code);
    return(0);
}