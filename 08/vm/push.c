#include "vm.h"

void	push_constant(int num, int fd)
{
	write_assignDA(num, fd);
	push_assign_inc(fd);
}

void	push_static(int num, int fd, char *direname)
{
	write_at(fd);
	write2file(fd, direname);
	write2file(fd, ".");
	ft_putnbr_fd(num, fd);
	write2file(fd, "\n");
	write_DeqM(fd);
	push_assign_inc(fd);
}

void	push_temp(int num, int fd)
{
	write_assignDA(num, fd);
	write_DeqPTR("R5", num, fd);
	push_assign_inc(fd);
}

void	push_pointer(int num, int fd)
{
	write_assignDA(num, fd);
	write_DeqPTR("THIS", num, fd);
	push_assign_inc(fd);
}

void	push_args(char *arg, int num, int fd)
{
	write_assignDA(num, fd);
	if(ft_strcmp(arg, "argument") == 0)
		write_DeqARG("ARG", num, fd);
	else if(ft_strcmp(arg, "local") == 0)
		write_DeqARG("LCL", num, fd);
	else if(ft_strcmp(arg, "this") == 0)
		write_DeqARG("THIS", num, fd);
	else if(ft_strcmp(arg, "that") == 0)
		write_DeqARG("THAT", num, fd);
	push_assign_inc(fd);
}

void	push(char **p, int fd, char *direname)
{
	char	*second;
	int		third;

	second = pick2space(*p);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	third = pick2space_num(p);
	if(ft_strcmp(second, "constant") == 0)
		push_constant(third, fd);
	else if(ft_strcmp(second, "static") == 0)
		push_static(third, fd, direname);
	else if(ft_strcmp(second, "temp") == 0)
		push_temp(third, fd);
	else if(ft_strcmp(second, "pointer") == 0)
		push_pointer(third, fd);
	else
		push_args(second, third, fd);
	free(second);
}