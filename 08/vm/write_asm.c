#include "vm.h"

void	push_assign_inc(int fd)
{
	write2file(fd,"@SP\nA=M\nM=D\n@SP\nM=M+1\n");
}

void	write_at(int fd)
{
	write2file(fd, "@");
}

void	write_nl(int fd)
{
	write2file(fd, "\n");
}

void	write_dec(int fd)
{
	write2file(fd, "@SP\nM=M-1\n");
}

void	write_AMD(int fd)
{
	write2file(fd, "A=M\nD=M\n");
}

void	write_Ainc(int fd)
{
	write2file(fd, "A=A+1\n");
}

void	write_Adec(int fd)
{
	write2file(fd, "A=A-1\n");
}