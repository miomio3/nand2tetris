#ifndef ASM_H_
#define ASM_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_bzero(void *s, int n);
void    ft_strcopy(char *ret, char *array);
int     ft_strlen(char *array);
void    safe_free(char *array);
char    *ft_strjoin_free1(char *array1, char *array2);

#endif