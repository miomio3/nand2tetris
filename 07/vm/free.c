#include "vm.h"

void    safe_free(char *array)
{
    if(array == NULL)
        return;
    free(array);
    array = NULL;
}
