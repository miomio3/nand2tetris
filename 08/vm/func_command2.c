#include "vm.h"

void	set_endframe(char *var, int fd)
{
	write2file(fd, "@R7\nM=M-1\nA=M\nD=M\n");
	write_at(fd);
	write2file(fd, var);
	write2file(fd, "\nM=D\n");
}

void	set_vars(int fd)
{
	write2file(fd, "@LCL\nD=M\n@R7\nM=D\n");
	set_endframe("THAT", fd);
	set_endframe("THIS", fd);
	set_endframe("ARG", fd);
	set_endframe("LCL", fd);
}

void	goto_return(int fd)
{
	write2file(fd, "@R6\nA=M\n0;JMP\n");
}

void	save_retaddr(int fd)
{
	write2file(fd, "@5\nD=A\n@LCL\nA=M-D\nD=M\n@R6\nM=D\n");
}

void	return_command(int fd)
{
	save_retaddr(fd);
	pop_args("argument", 0, fd);//pop ARG
	write2file(fd, "@ARG\nD=M\n@SP\nM=D+1\n");//SP=ARG+1
	set_vars(fd);
	goto_return(fd);
}
