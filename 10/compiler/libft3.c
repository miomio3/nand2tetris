#include "compiler.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = len - start + 1;
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

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	if ((n / 10) * sign > 0)
	{
		ft_putnbr_fd((n / 10) * sign, fd);
		ft_putchar_fd('0' + (n % 10) * sign, fd);
	}
	else
		ft_putchar_fd('0' + n * sign, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
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
