#include "vm.h"

void	label(char **p, int fd)
{
	char	*label;

	label = pick2space(*p);
	write2file(fd, "(");
	write2file(fd, label);
	write2file(fd, ")\n");
	free(label);
}

void	goto_label(char **p, int fd)
{
	char	*label;

	label = pick2space(*p);
	write_at(fd);
	write2file(fd, label);
	write2file(fd, "\n0;JMP\n");
}

void	if_goto(char **p, int fd)
{
	char	*label;

	label = pick2space(*p);
	write2file(fd, "@SP\nM=M-1\nA=M\nD=M\n");
	write_at(fd);
	write2file(fd, label);
	write2file(fd, "\nD;JNE\n");
}