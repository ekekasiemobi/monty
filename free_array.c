#include "monty.h"
/**
 * free_array - free all memory allocated
 */
void free_array(void)
{
	int i = 0;

	for (; mont->arr[i] != NULL; i++)
		free(mont->arr[i]);
	free(mont->arr);
	mont->arr = NULL;
}
