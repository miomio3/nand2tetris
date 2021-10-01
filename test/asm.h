#ifndef ASM_H_
#define ASM_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    ERROR,
    NOERROR
}error;

typedef struct  token
{
    int             type;
    char            *s1;
    char            *s2;
    struct token    *next;
}               token;

typedef struct  s_symbols
{
    struct s_symbols    *next;
    char                *symbol;
    int                 memory;
}               t_symbols;

//libft
void        ft_bzero(void *s, int n);
void        ft_strcopy(char *ret, char *array);
int         ft_strlen(char *array);
void        safe_free(char *array);
char        *ft_strjoin_free1(char *array1, char *array2);
//libft2
int          ft_isspace(char *p);
char	     *ft_strdup(char *s);
//file
void         read_file(int fd, char *array, char **assembly);
void         open_file(int *fd, char **argv, char *array);
//symbol_table
t_symbols    *init_symbol_table(void);
int          add_symbol(t_symbols **symbols, char *s, int memory);

#endif