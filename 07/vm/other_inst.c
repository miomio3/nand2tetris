#include "vm.h"

void	add_sub_inst(char *inst, int fd)
{
	if(ft_strcmp(inst, "add") == 0)
		write2file(fd, "D=D+M\nM=D\n");
	else if(ft_strcmp(inst, "sub") == 0)
		write2file(fd, "D=M-D\nM=D\n");
}

void	and_inst(int fd)
{
	write2file(fd, "M=D&M\n");
}

void	or_inst(int fd)
{
	write2file(fd, "M=D|M");
}

void	cmp_inst(char *inst, int fd)
{
	write2file(fd, "D=M-D\n");
	write2file(fd, "M=-1\n");
	write_at(fd);
	write2file(fd, inst);
	write2file(fd, "_last\nD;");
	if(ft_strcmp(inst, "eq") == 0)
		write2file(fd, "JEQ\n");
	else if(ft_strcmp(inst, "gt") == 0)
		write2file(fd, "JGT\n");
	else if(ft_strcmp(inst, "lt") == 0)
		write2file(fd, "JLT\n");
	write2file(fd, "@SP\nA=M-1\nM=0\n(");
	write2file(fd, inst);
	write2file(fd, "_last)\n");
}

void	other_inst(char *inst, int fd)
{
	write_dec(fd);
	write_AMD(fd);
	write_Adec(fd);
	if(ft_strcmp(inst, "add") == 0 || ft_strcmp(inst, "sub") == 0)
		add_sub_inst(inst, fd);
	else if(ft_strcmp(inst, "and") == 0)
		and_inst(fd);
	else if(ft_strcmp(inst, "or") == 0)
		or_inst(fd);
	else
		cmp_inst(inst, fd);
}