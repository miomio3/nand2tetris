#include "vm.h"

void	label(char **p, int fd)
{
	char	*label;
	int		local_num;

	label = pick2space(*p);
	write2file(fd, "(");
	write2file(fd, label);
	write2file(fd, ")\n");
	free(label);
}