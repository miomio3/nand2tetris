#include "vm.h"

void	push_assign_inc(int fd)
{
	write2file(fd,"@SP\nA=M\nM=D\n@SP\nM=M+1\n");
}

void	write_at(int fd)
{
	write2file(fd, "@");
}

void	write_DeqA(int fd)
{
	write2file(fd, "\nD=A\n");
}

void	write_assignDA(int num, int fd)
{
	char	*str;

	write_at(fd);
	ft_putnbr_fd(num, fd);
	write_DeqA(fd);
}

void	write_DeqPTR(char *ptr , int num, int fd)
{
	write_at(fd);
	write2file(fd, ptr);
	write2file(fd, "\nA=A+D\n");
	write2file(fd, "D=M\n");
}

void	write_DeqARG(char *arg, int num, int fd)
{
	write_at(fd);
	write2file(fd, arg);
	write2file(fd, "\nA=M+D\n");
	write2file(fd, "D=M\n");
}