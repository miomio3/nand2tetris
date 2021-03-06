#include "vm.h"

void	perse_write(int fd, char **p, char *direname, char *filename, int i)
{
	char	*first;

	first = pick2space(*p);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	if(ft_strcmp(first, "push") == 0)
		push(p, fd, direname, filename);
	else if(ft_strcmp(first, "pop") == 0)
		pop(p, fd, direname, filename);
	else if(ft_strcmp(first, "neg") == 0 || ft_strcmp(first, "not") == 0)
		neg_not(first, fd);
	else if(ft_strcmp(first, "label") == 0)
		label(p, fd);
	else if(ft_strcmp(first, "function") == 0)
		function(p, fd);
	else if(ft_strcmp(first, "goto") == 0)
		goto_label(p, fd);
	else if(ft_strcmp(first, "if-goto") == 0)
		if_goto(p, fd);
	else if(ft_strcmp(first, "return") == 0)
		return_command(fd);
	else if(ft_strcmp(first, "call") == 0)
		call_command(p, fd, i);
	else
		other_inst(first, fd, i);
	free(first);
}

void	vm(char *vm_code, char *direname, char *filename, int asmfd)
{
	char	*p;
	char 	*test;
	int		i;

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
			perse_write(asmfd, &p, direname, filename, i);
			p = nl(p);
		}
		i++;
	}
	write2file(asmfd, "\0");
}