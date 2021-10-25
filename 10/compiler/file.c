#include "compiler.h"

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


void	open_jackfile(int *fd, char *argv)
{
	*fd = open(argv, O_RDONLY);
	if(*fd == -1)
	{
		printf("JACKfile couldn't opne.\n");
		exit(-1);
	}
}

int	open_vmfile(int *fd, char *file_name)
{
	*fd = open(file_name, O_WRONLY);
	if(*fd == -1)
	{
		printf("VMfile couldn't opne.\n");
		exit(-1);
	}
	return(NOERROR);
}

void	read_file2(int fd, char *buf, char **code)
{
	*code = NULL;
    while(read(fd, buf, 100) > 0)
    {
        *code = ft_strjoin_free1(*code, buf);
        ft_bzero(buf, 101);
    }
}

void	read_file(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*buf;
	char	*code;
	char	*filename;

	init_buf(&buf);
	i = 1;
    while(i < argc)
    {
        filename = pick_filename(argv[i]);
        open_jackfile(&fd, argv[i]);
        read_file2(fd, buf, &code);
		//compiler関数
        ft_bzero(code, ft_strlen(code));
		free(code);
        free(filename);
        i++;
    }
}


void	read_dir(char **argv)
{
	DIR				*dir;
	struct	dirent	*dp;

	dir = opendir(argv[1]);
	dp = readdir(dir);
	while(dp != NULL)
	{
		printf("%s\n", dp->d_name);
		//ファイル読み取り関数
		dp = readdir(dir);
	}
	closedir(dir);
}