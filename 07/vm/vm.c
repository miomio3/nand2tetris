#include "vm.h"

void	perse_write(int fd, char **p, char *file_name)
{
	char	*first;

	first = pick2space(*p);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	if(ft_strcmp(first, "push") == 0)
		push(p, fd, file_name);
	else if(ft_strcmp(first, "pop") == 0)
		pop(p, fd, file_name);
	else if(ft_strcmp(first, "neg") == 0 || ft_strcmp(first, "not") == 0)
		neg_not(first, fd);
	else
		other_inst(first, fd);
	free(first);
}

void	vm(char *vm_code, char *file_name)
{
	int		fd;
	char	*p;
	char 	*test;

	if(open_file2(&fd, "vm.asm") == ERROR)
		return;
	p = vm_code;
	while(*p)
	{
		while(ft_isspace(p))
            p++;
        if((p[0] == '/' && p[1] == '/') || p[0] == '\n' || p[0] == 13)
            p = nl(p);
		else
		{
			perse_write(fd, &p, file_name);
			p = nl(p);
		}
	}
	close(fd);
}