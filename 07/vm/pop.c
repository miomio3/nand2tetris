#include "vm.h"

void	pop_static(int num, int fd, char *file_name)
{
	write_at(fd);
	write2file(fd, file_name);
	write2file(fd, ".");
	ft_putnbr_fd(num, fd);
	write_nl(fd);
}

void	pop_temp(int third, int fd)
{
	write2file(fd, "@R5\n");
	while(third--)
		write_Ainc(fd);
}

void	pop_pointer(int third, int fd)
{
	write2file(fd, "@THIS\n");
	while(third--)
		write_Ainc(fd);
}

void	pop_args(char *arg, int third, int fd)
{
	if(ft_strcmp(arg, "argument") == 0)
		write2file(fd, "@ARG\n");
	else if(ft_strcmp(arg, "local") == 0)
		write2file(fd, "@LCL\n");
	else if(ft_strcmp(arg, "this") == 0)
		write2file(fd, "@THIS\n");
	else if(ft_strcmp(arg, "that") == 0)
		write2file(fd, "@THAT\n");
	write2file(fd, "A=M\n");
	while(third--)
		write_Ainc(fd);
}

void	pop(char **p, int fd, char *file_name)
{
	char	*second;
	int		third;

	second = pick2space(*p);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	third = pick2space_num(p);
	write_dec(fd);
	write_AMD(fd);
	if(ft_strcmp(second, "static") == 0)
		pop_static(third, fd, file_name);
	else if(ft_strcmp(second, "temp") == 0)
		pop_temp(third, fd);
	else if(ft_strcmp(second, "pointer") == 0)
		pop_pointer(third, fd);
	else
		pop_args(second, third, fd);
	write_MeqD(fd);
	free(second);
}