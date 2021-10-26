#include "compiler.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = strlen(s1) + strlen(s2);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		*(p + i) = *s1++;
		i++;
	}
	while (*s2)
	{
		*(p + i) = *s2++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

char    *ft_strjoin_free1(char *array1, char *array2)
{
    char    *ret;
    int     n;
    int     array1_len;

	array1_len = 0;
	n = 0;
	if(array1 != NULL)
   		array1_len = strlen(array1);//ヌル文字を含まない長さ
	n = array1_len + strlen(array2);
    ret = malloc(sizeof(char) * (n + 1));
    if(ret == NULL)
    {
        safe_free(array1);
        safe_free(array2);
        exit(-1);
    }
    if(array1 != NULL)
        strcpy(ret, array1);
    strcpy(&ret[array1_len], array2);
    safe_free(array1);
    return(ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = len - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
