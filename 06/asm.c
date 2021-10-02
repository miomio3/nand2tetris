#include "asm.h"

void	assembler(char *assembly)
{
	int			fd;
	t_symbols	*symbols;
	token		*token;

	symbols = init_symbol_table();
	token = perser(assembly, symbols);
	free(assmbly);
	if(open_file2(&fd, "asm.hack") == ERROR)
	{
		free_symbols(&symbols);
		free_tokens(&token);
		return;
	}
	
	free_symbols(&symbols);
	free_tokens(&token);
	//openfile .. write .. closefile
}