#include "vm.h"

void	push_assign_inc(int fd)
{
	write2file(fd,"@SP\nA=M\nM=D\n@SP\nM=M+1\n");
}