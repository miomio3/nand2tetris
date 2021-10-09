#include "vm.h"

void	push(char **p, int fd, char *file_name)
{
	char	*second;
	int		third;

	second = pick2space(p);
	while(ft_isspace(*p))
    	(*p)++;
	third = pick2space_num(p);
	if(ft_strcmp(second, "constant") == TRUE)
		push_constant(third, fd);//途中
	else if(ft_strcmp(second, "temp") == TRUE || ft_strcmp(second, "poiter") == TRUE)
		push_temp_pointer(second, third, fd);//途中
	else if(ft_strcmp(second, "static") == TRUE)
		push_static(third, fd, file_name);//途中
	else
		push_args();//途中
	push_assign_inc(fd);
	free(second);
}