#include "monty.h"
/**
 * print_all - prints all the values on stack from top to the last
 *
 * @stack: pointer to stack to print`
 * @line_count: number of lines counted
 */
void print_all(stack_t **stack, unsigned int line_count)
{
	stack_t *new;
	(void)line_count;

	new = *stack;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}


/**
 * print_int - prints top item on the stack
 *
 * @stack: pointer to stacck to print
 * @line_count: number of lines counted
 */
void print_int(stack_t **stack, unsigned int line_count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L %d: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * _nop - function does nothing
 *
 * @stack: pointer to stacck to print
 * @line_count: number of lines counted
 */
void nop(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
}
