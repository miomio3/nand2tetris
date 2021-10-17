#include "vm.h"

void	neg_not(char *inst, int fd)
{
	write2file(fd, "@SP\nA=M-1\n");
	if(ft_strcmp(inst, "neg") == 0)
		write2file(fd, "M=-M\n");
	else if(ft_strcmp(inst, "not") == 0)
		write2file(fd, "M=!M\n");
}