#include "asm.h"

void	write_Abinary(int fd, token *Token)
{
	char			*s;
	unsigned char	memory;
	unsigned char	bit;
	int				i;

	write2file(fd, "0");
	memory = Token->memory;
	s = malloc(sizeof(char) * 16);
	ft_bzero(s, 16);
	i = 15;
	while(i--)
	{
		bit = (memory>>i) & 1;
		s[14 - i] = '0' + bit;
	}
	write2file(fd, s);
	write2file(fd, "\n");
	free(s);
}

void	write_binary(int fd, token *Token, t_symbols *symbols)
{
	while(Token)
	{
		if(Token->type == C)
			write_Cbinary(fd, Token);
		else if(Token->type == A)
			write_Abinary(fd, Token);
		else if(Token->type == J)
			write_Jbinary(fd, Token);
		Token = Token->next;
	}
}