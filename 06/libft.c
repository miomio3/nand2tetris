#include "asm.h"

void    ft_bzero(void *s, int n)
{
    unsigned char *d;
    int           i;

    d = s;
    i = 0;
    while(i < n)
    {
        d[i] = 0;
        i++;
    }
}

void    ft_strcopy(char *ret, char *array)
{
    int i;

    i = 0;
    while(array[i])
    {
        ret[i] = array[i];
        i++;
    }
    ret[i] = '\0';
}

int ft_strlen(char *array)
{
    int i;

    if(array == NULL)
        return(0);
    i = 0;
    while(array[i])
        i++;
    return(i);
}

void    safe_free(char *array)
{
    if(array == NULL)
        return;
    free(array);
    array = NULL;
}

char    *ft_strjoin_free1(char *array1, char *array2)
{
    char    *ret;
    int     n;
    int     array1_len;

    array1_len = ft_strlen(array1);//ヌル文字を含まない長さ
    n = array1_len + ft_strlen(array2);
    ret = malloc(sizeof(char) * (n + 1));
    if(ret == NULL)
    {
        safe_free(array1);
        safe_free(array2);
        exit(-1);
    }
    if(array1 != NULL)
        ft_strcopy(ret, array1);
    ft_strcopy(&ret[array1_len], array2);
    safe_free(array1);
    return(ret);
}
