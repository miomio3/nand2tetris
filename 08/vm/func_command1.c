#include "vm.h"

void	function(char **p, int fd)
{
	int	local_num;

	label(p, fd);
	*p = next_space(p);
	while(ft_isspace(*p))
        (*p)++;
	local_num = pick2space_num(p);
	while(local_num--)
		push_constant(0, fd);
}
