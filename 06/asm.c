#include "asm.h"

void	assembler(char *assembly)
{
	t_symbols	*symbols;
	token		*token;

	symbols = init_symbol_table();
	perser(assembly, symbols);
}