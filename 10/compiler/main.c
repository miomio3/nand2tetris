#include "compiler.h"

int	main(int argc, char **argv)
{
	if(is_file(argv[1]) == TRUE)
		read_files(argc, argv);
	else
		read_dir(argv);
	return(0);
}