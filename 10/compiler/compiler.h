#ifndef	COMPILER_H_
#define	COMPILER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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
void	safe_free(char *array);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		strncmp2(const char *s1, const char *s2);
//libft2
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free1(char *array1, char *array2);
char	*ft_substr(char *s, unsigned int start, size_t len);
//pick
char	*pick2space(char *s);
int		pick2space_num(char **str);
char	*pick_direname(char *arg);
char	*pick_filename(char *argv);
//skip
char	*nnest(char *s);
char	*nl(char *p);
void	skip_comment_space(char **code);

#endif