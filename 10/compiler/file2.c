#include "compiler.h"

char	*create_V_filename(char *J_filename)
{
	char	*re;
	char	*filename;

	filename = pick_filename(J_filename);
	re = ft_strjoin(filename, ".vm");
	free(filename);
	return(re);
}

void    init_buf(char **array)
{
    *array = malloc(sizeof(char) * 101);
    if(*array == NULL)
        exit(-1);
    ft_bzero(*array, 101);
}

int	is_file(char *argv)
{
	int	i;

	i = 0;
	while(argv[i] != '\0' && argv[i + 4] != '\0')
	{
		if(argv[i] == '.' && argv[i + 1] == 'j' && argv[i + 2] == 'a' && argv[i + 3] == 'c' && argv[i + 4] == 'k')
			return(TRUE);
		i++;
	}
	return(FALSE);
}