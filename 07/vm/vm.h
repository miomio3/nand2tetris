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

typedef enum
{
	TRUE,
	FALSE
}		true_false;

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
char		*next_space(char **p);
//libft3
char		*ft_substr(char *s, unsigned int start, size_t len);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
//neg_not
void		neg_not(char *inst, int fd);
//other_inst
void		other_inst(char *inst, int fd, int i);
//pick
char		*pick2space(char *s);
int			pick2space_num(char **str);
char		*pick_filename(char *arg);
//pop
void		pop(char **p, int fd, char *file_name);
//push
void		push(char **p, int fd, char *file_name);
//vm
void		vm(char *vm_code, char *file_name);
//write_asm.h
void		push_assign_inc(int fd);
void		write_at(int fd);
void		write_nl(int fd);
void		write_dec(int fd);
void		write_AMD(int fd);
void		write_Ainc(int fd);
void		write_Adec(int fd);
//write_asm2.c
void		write_DeqA(int fd);
void		write_MeqD(int fd);
void		write_DeqM(int fd);
void		write_DeqPTR(char *ptr , int num, int fd);
void		write_DeqARG(char *arg, int num, int fd);
void		write_assignDA(int num, int fd);

#endif