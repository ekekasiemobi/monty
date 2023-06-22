#include "monty.h"
/**
 * initialize - initialize parameters of param structure
 */
void initialize(void)
{
	mont = malloc(sizeof(param));
	if (!mont)
		malloc_error();
	mont->n = 0;
	mont->line_number = 0;
	mont->arr = NULL;
}
