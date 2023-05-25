#include "shell.h"

/**
 * bfree - NULLs the address and frees a pointer
 * @ptr: address of the free pointer
 *
 * Return: If released, 1; else, 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);

}
