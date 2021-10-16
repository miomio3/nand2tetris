#include "vm.h"

void	push_retaddr(int fd, int i)
{
	write2file(fd, "@return");
	ft_putnbr_fd(i, fd);
	write2file(fd, "\nD=A\n");
	push_assign_inc(fd);
}

void	push_addr(char *var, int fd)
{
	write_at(fd);
	write2file(fd, var);
	write2file(fd, "\nD=M\n");
	push_assign_inc(fd);
}

void	set_arg(int fd, int nargs)
{
	write2file(fd, "@5\nD=A\n@SP\nD=M-D\n");
	while(nargs--)
		write2file(fd, "D=D-1\n");
	write2file(fd, "@ARG\nM=D\n");
}

void	set_lcl(int fd)
{
	write2file(fd, "@SP\nD=M\n@LCL\nM=D\n");
}

void	set_return_label(int fd, int i)
{
	write2file(fd, "(return");
	ft_putnbr_fd(i, fd);
	write2file(fd, ")\n");
}

void	call_command(char **p, int fd, int i)
{
	int		nargs;
	char	*func_name;

	push_retaddr(fd, i);
	push_addr("LCL", fd);
	push_addr("ARG", fd);
	push_addr("THIS", fd);
	push_addr("THAT", fd);
	func_name = pick2space(*p);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	nargs = pick2space_num(p);
	set_arg(fd, nargs);
	set_lcl(fd);
	goto_label(&func_name, fd);
	set_return_label(fd, i);
}