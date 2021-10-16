#include "vm.h"

void	perse_write(int fd, char **p, char *direname, int i)
{
	char	*first;

	first = pick2space(*p);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	if(ft_strcmp(first, "push") == 0)
		push(p, fd, direname);
	else if(ft_strcmp(first, "pop") == 0)
		pop(p, fd, direname);
	else if(ft_strcmp(first, "neg") == 0 || ft_strcmp(first, "not") == 0)
		neg_not(first, fd);
	else if(ft_strcmp(first, "label") == 0)
		label(p, fd);
	else if(ft_strcmp(first, "function") == 0)
		function(p, fd);
	else
		other_inst(first, fd, i);
	free(first);
}

void	vm(char *vm_code, char *direname)
{
	int		fd;
	char	*p;
	char 	*test;
	int		i;

	if(open_file2(&fd, "vm.asm") == ERROR)
		return;
	p = vm_code;
	i = 0;
	while(*p)
	{
		while(ft_isspace(p))
            p++;
        if((p[0] == '/' && p[1] == '/') || p[0] == '\n' || p[0] == 13)
            p = nl(p);
		else
		{
			perse_write(fd, &p, direname, i);
			p = nl(p);
		}
		i++;
	}
	write2file(fd, "\0");
	close(fd);
}