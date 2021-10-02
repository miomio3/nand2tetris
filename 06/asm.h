#ifndef ASM_H_
#define ASM_H_

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
	A,
	C
}		AorC;

typedef struct	token
{
	int				type;//A命令かC命令か
	int				memory;//A命令時の数字
    char			*s1;//C命令の時のA=など
    char			*s2;//C命令の時のD-1など
	int				order;//何番目の命令か
    struct token	*next;
}				token;

typedef struct	s_symbols
{
    struct s_symbols	*next;
    char				*symbol;
    int					memory;
}				t_symbols;

//asm
void		assembler(char *assembly);
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
//file
void		read_file(int fd, char *array, char **assembly);
void		open_file(int *fd, char **argv, char *array);
//symbol_table
t_symbols	*init_symbol_table(void);
void		add_symbol(t_symbols **symbols, char *s, int memory);
void		add_para_symbol(t_symbols **symbols, char *p, token *Token);
int			search_symbol(t_symbols **symbols, char *var);
//perser
token		*perser(char *assembly, t_symbols *symbols);
//token
int			count_Token(token *Token);
//tokenA
void		add_Atoken(t_symbols **symbols, char *s, token **Token);

#endif