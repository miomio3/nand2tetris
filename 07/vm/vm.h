#ifndef VM_H_
#define VM_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef	enum
{
    ERROR,
    NOERROR
}		error;

typedef enum
{
	EXIST,
	NOEXIST
}		exist;

//file
void		read_file(int fd, char *array, char **assembly);
void		open_file(int *fd, char **argv, char *array);
int			open_file2(int *fd, char *file_name);
void		write2file(int fd, char *s);
//free
void    	safe_free(char *array);
//libft
void		ft_bzero(void *s, int n);
void		ft_strcopy(char *ret, char *array);
int			ft_strlen(char *array);
void		safe_free(char *array);
char		*ft_strjoin_free1(char *array1, char *array2);
//libft2
int			ft_isspace(char *p);
char		*ft_strdup(char *s);
int			ft_strcmp(char *s1, char *s2);
char		*nl(char *p);
//pick
char		*pick_first(char **str);
//pop
void		pop(char *p);
//vm
void		vm(char *vm_code);

#endif