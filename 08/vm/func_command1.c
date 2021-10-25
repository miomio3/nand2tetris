#include "vm.h"

void	goto_sysinit(char *s, int fd)
{
	write_at(fd);
	write2file(fd, s);
	write2file(fd, "\n0;JMP\n");
}

void	call_sysinit(char **p, int fd, int i)
{
	int		nargs;

	init_SP(fd);
	push_retaddr(fd, i);
	push_addr("LCL", fd);
	push_addr("ARG", fd);
	push_addr("THIS", fd);
	push_addr("THAT", fd);
	set_arg(fd, 0);
	set_lcl(fd);
	goto_sysinit("Sys.init", fd);
	set_return_label(fd, i);
}

void	function(char **p, int fd)
{
	int		local_num;
	char	*func;

	func = pick2space(*p);
	if(ft_strcmp(func, "Sys.init") == 0)
		call_sysinit(p, fd, 0);
	label(p, fd);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	local_num = pick2space_num(p);
	while(local_num--)
		push_constant(0, fd);
}
