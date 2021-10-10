#include "vm.h"

void	push_constant(int num, int fd)
{
	write_assignDA(num, fd);
}

void	push_static(int num, int fd, char *filename)
{
	write_at(fd);
	write2file(fd, filename);
	write2file(fd, ".");
	ft_putnbr_fd(num, fd);
	write_DeqA(fd);
}

void	push_temp(int num, int fd)
{
	write_assignDA(num, fd);
	write_DeqPTR("R5", num, fd);
}

void	push_pointer(int num, int fd)
{
	write_assignDA(num, fd);
	write_DeqPTR("THIS", num, fd);
}

void	push_args(char *arg, int num, int fd)
{
	write_assignDA(num, fd);
	if(ft_strcmp(arg, "argument") == TRUE)
		write_DeqARG("ARG", num, fd);
	else if(ft_strcmp(arg, "local") == TRUE)
		write_DeqARG("LCL", num, fd);
	else if(ft_strcmp(arg, "this") == TRUE)
		write_DeqARG("THIS", num, fd);
	else if(ft_strcmp(arg, "that") == TRUE)
		write_DeqARG("THAT", num, fd);
}

void	push(char **p, int fd, char *file_name)
{
	char	*second;
	int		third;

	second = pick2space(*p);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	third = pick2space_num(p);
	if(ft_strcmp(second, "constant") == TRUE)
		push_constant(third, fd);
	else if(ft_strcmp(second, "static") == TRUE)
		push_static(third, fd, file_name);
	else if(ft_strcmp(second, "temp") == TRUE)
		push_temp(third, fd);
	else if(ft_strcmp(second, "pointer") == TRUE)
		push_pointer(third, fd);
	else
		push_args(second, third, fd);
	push_assign_inc(fd);
	free(second);
}