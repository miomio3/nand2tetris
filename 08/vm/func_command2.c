#include "vm.h"

void	set_endframe(char *var, int fd)
{
	write2file(fd, "@R5\nM=M-1\nA=M\nD=M\n");
	write_at(fd);
	write2file(fd, var);
	write2file(fd, "\nM=D\n");
}

void	set_vars(int fd)
{
	write2file(fd, "@LCL\nD=M\n@R5\nM=D\n");
	set_endframe("THAT", fd);
	set_endframe("THIS", fd);
	set_endframe("ARG", fd);
	set_endframe("LCL", fd);
}

void	goto_return(int fd)
{
	write2file(fd, "@R5\nM=M-1\nA=M\nD=M\n");
	write2file(fd, "@D\n0;JMP\n");
}

void	return_command(int fd)
{
	pop_args("argument", 0, fd);//pop ARG
	write2file(fd, "@ARG\nD=M\n@SP\nM=D+1\n");//SP=ARG+1
	set_vars(fd);
	goto_return(fd);
}
