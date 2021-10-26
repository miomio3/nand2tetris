#include "compiler.h"

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

int	strncmp2(const char *s1, const char *s2)
{
	return(strncmp(s1, s2, strlen(s2)));
}


void    safe_free(char *array)
{
    if(array == NULL)
        return;
    free(array);
    array = NULL;
}
