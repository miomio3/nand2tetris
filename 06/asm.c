#include "asm.h"

void	assembler(char *assembly)
{
	int			fd;
	t_symbols	*symbols;
	token		*Token;

	symbols = init_symbol_table();
	Token = perser(assembly, symbols);
	/* while(symbols)//debug
	{
		printf("%d\n", symbols->memory);
		printf("%s\n", symbols->symbol);
		symbols = symbols->next;
	} */
	if(open_file2(&fd, "asm.hack") == ERROR)
	{
		free_symbols(&symbols);
		free_token(&Token);
		return;
	}
	write_binary(fd, Token, symbols);
	free_symbols(&symbols);
	free_token(&Token);
	close(fd);
}