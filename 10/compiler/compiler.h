#ifndef	COMPILER_H_
#define	COMPILER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

typedef	enum
{
	TRUE,
	FALSE
}	true_false;

typedef	enum
{
	ERROR,
	NOERROR
}	error_noerror;

//compiler
void	compiler(char *code, char *filename);
//dir
void	read_dir(char **argv);
//file
void	open_jackfile(int *fd, char *argv);
void	open_vmfile(int *fd, char *filename);
void	read_jackfile(int fd, char *buf, char **code);
void	read_files(int argc, char **argv);
//file2
void    init_buf(char **array);
int		is_file(char *argv);
char	*create_V_filename(char *J_filename);
//libft
void    ft_bzero(void *s, int n);
void	ft_strcopy(char *ret, char *array);
int		ft_strlen(const char *array);
void	safe_free(char *array);
char	*ft_strjoin_free1(char *array1, char *array2);
//libft2
int		ft_isspace(char *p);
char	*ft_strdup(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*nl(char *p);
char	*next_space(char **p);
//libft3
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
//pick
char	*pick2space(char *s);
int		pick2space_num(char **str);
char	*pick_direname(char *arg);
char	*pick_filename(char *argv);

#endif