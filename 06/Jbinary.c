#include "asm.h"

void	write_jmp(int fd, token *Token)
{
	if(ft_strcmp(Token->assign, "JGT") == 0)
		write2file(fd, "001");
	else if(ft_strcmp(Token->assign, "JEQ") == 0)
		write2file(fd, "010");
	else if(ft_strcmp(Token->assign, "JGE") == 0)
		write2file(fd, "011");
	else if(ft_strcmp(Token->assign, "JLT") == 0)
		write2file(fd, "100");
	else if(ft_strcmp(Token->assign, "JNE") == 0)
		write2file(fd, "101");
	else if(ft_strcmp(Token->assign, "JLE") == 0)
		write2file(fd, "110");
	else if(ft_strcmp(Token->assign, "JMP") == 0)
		write2file(fd, "111");
}

void	write_Jbinary(int fd, token *Token)
{
	write2file(fd, "111");
	if(ft_strcmp(Token->save, "D") == 0)
		write2file(fd, "0001100");
	else if(ft_strcmp(Token->save, "0") == 0)
		write2file(fd, "0101010");
	write2file(fd, "000");
	write_jmp(fd, Token);
	write2file(fd, "\n");
}