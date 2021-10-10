#include "vm.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (*s == '\0' || start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
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
