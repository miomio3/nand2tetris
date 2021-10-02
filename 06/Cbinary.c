#include "asm.h"


void	write_Mbinary(int fd, token *Token)
{
	write2file(fd, "1");
	if(ft_strcmp(Token->assign, "M") == 0)
		write2file(fd, "110000");
	else if(ft_strcmp(Token->assign, "!M") == 0)
		write2file(fd, "110001");
	else if(ft_strcmp(Token->assign, "-M") == 0)
		write2file(fd, "110011");
	else if(ft_strcmp(Token->assign, "M+1") == 0)
		write2file(fd, "110111");
	else if(ft_strcmp(Token->assign, "M-1") == 0)
		write2file(fd, "110010");
	else if(ft_strcmp(Token->assign, "D+M") == 0)
		write2file(fd, "000010");
	else if(ft_strcmp(Token->assign, "D-M") == 0)
		write2file(fd, "010011");
	else if(ft_strcmp(Token->assign, "M-D") == 0)
		write2file(fd, "000111");
	else if(ft_strcmp(Token->assign, "D&M") == 0)
		write2file(fd, "000000");
	else if(ft_strcmp(Token->assign, "D|M") == 0)
		write2file(fd, "010101");
}

void	write_NoMbinary(int fd, token *Token)
{
	write2file(fd, "0");
	if(ft_strcmp(Token->assign, "0") == 0)
		write2file(fd, "101010");
	else if(ft_strcmp(Token->assign, "1") == 0)
		write2file(fd, "111111");
	else if(ft_strcmp(Token->assign, "-1") == 0)
		write2file(fd, "111010");
	else if(ft_strcmp(Token->assign, "D") == 0)
		write2file(fd, "001100");
	else if(ft_strcmp(Token->assign, "A") == 0)
		write2file(fd, "110000");
	else if(ft_strcmp(Token->assign, "!D") == 0)
		write2file(fd, "001101");
	else if(ft_strcmp(Token->assign, "!A") == 0)
		write2file(fd, "110001");
	else if(ft_strcmp(Token->assign, "-D") == 0)
		write2file(fd, "001111");
	else if(ft_strcmp(Token->assign, "-A") == 0)
		write2file(fd, "110011");
	else if(ft_strcmp(Token->assign, "D+1") == 0)
		write2file(fd, "011111");
	else if(ft_strcmp(Token->assign, "A+1") == 0)
		write2file(fd, "110111");
	else if(ft_strcmp(Token->assign, "D-1") == 0)
		write2file(fd, "001110");
	else if(ft_strcmp(Token->assign, "A-1") == 0)
		write2file(fd, "110010");
	else if(ft_strcmp(Token->assign, "D+A") == 0)
		write2file(fd, "000010");
	else if(ft_strcmp(Token->assign, "D-A") == 0)
		write2file(fd, "010011");
	else if(ft_strcmp(Token->assign, "A-D") == 0)
		write2file(fd, "000111");
	else if(ft_strcmp(Token->assign, "D&A") == 0)
		write2file(fd, "000000");
	else if(ft_strcmp(Token->assign, "D|A") == 0)
		write2file(fd, "010101");
}

void	write_dest(int fd, token *Token)
{
	if(is_A(Token->save) == EXIST)
		write2file(fd, "1");
	else if(is_A(Token->save) == NOEXIST)
		write2file(fd, "0");
	if(is_D(Token->save) == EXIST)
		write2file(fd, "1");
	else if(is_D(Token->save) == NOEXIST)
		write2file(fd, "0");
	if(is_M(Token->save) == EXIST)
		write2file(fd, "1");
	else if(is_M(Token->save) == NOEXIST)
		write2file(fd, "0");
}

void	write_Cbinary(int fd, token *Token)
{
	write2file(fd, "111");
	if(is_M(Token->assign) == EXIST)
		write_Mbinary(fd, Token);
	else
		write_NoMbinary(fd, Token);
	write_dest(fd, Token);
	write2file(fd, "000\n");
}
