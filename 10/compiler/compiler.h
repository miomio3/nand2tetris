#ifndef	COMPILER_H_
#define	COMPILER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>

typedef	enum
{
	TRUE,
	FALSE
}	true_false;

typedef	enum
{
	ERROR,
	NOERROR
}	error_noerror;

int		is_file(char *argv);
void	read_dir(char **argv);

#endif