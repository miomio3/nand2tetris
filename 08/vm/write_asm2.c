#include "vm.h"

void	write_DeqA(int fd)
{
	write2file(fd, "\nD=A\n");
}

void	write_MeqD(int fd)
{
	write2file(fd, "M=D\n");
}

void	write_DeqM(int fd)
{
	write2file(fd, "D=M\n");
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

void	write_assignDA(int num, int fd)
{
	char	*str;

	write_at(fd);
	ft_putnbr_fd(num, fd);
	write_DeqA(fd);
}

void	write_assign0(int fd)
{
	write2file(fd, "\n");
}

void	init_SP(int fd)
{
	write2file(fd, "@256\nD=A\n@SP\nM=D\n");
	write2file(fd, "@ARG\nM=D\n");
}