#include "asm.h"

void	assembler(char *assembly)
{
	t_symbols	*symbols;

	symbols = init_symbol_table();
	perser(assembly, symbols);
}