#include "vm.h"

void	perse_write(int fd, char *p)
{
	char	*first;

	first = pick_first(&p);
	printf("%s\n", first);
	while(ft_isspace(p))
            p++;
	first = pick_first(&p);
	printf("%s\n", first);
	/* if(ft_strcmp(first, "pop") == 0)
		pop(fd, p);
	else if(ft_strcmp(first, "push") == 0)
		push(fd, p);
	else
		inst(fd, p); */
}

void	vm(char *vm_code)
{
	int		fd;
	char	*p;

	/* if(open_file2(&fd, "vm.asm") == ERROR)
		return; */
	p = vm_code;
	while(*p)
	{
		while(ft_isspace(p))
            p++;
        if((p[0] == '/' && p[1] == '/') || p[0] == '\n' || p[0] == 13)
            p = nl(p);
		else
		{
			perse_write(fd, p);
			p = nl(p);
		}
	}
	close(fd);
}