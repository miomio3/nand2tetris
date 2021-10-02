#include "unistd.h"
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	write2file(int fd, char *s)
{
	write(fd, s, strlen(s));
}

int	main(void)
{
	int fd;
	char s[3];
	//fd = open("asm.hack", O_WRONLY);
	//write2file(fd, "test\n");
	s[0] = 'A';
	s[1] = 'B';
	s[2] = '\0';
	printf("%s", s);
	return(0);
}