#include "monty.h"
/**
 * pop - a function that delete on a stack
 * @stack: a struct node pointer
 * @line: number of lines counted
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *next_val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	next_val = (*stack)->next;
	free(*stack);
	*stack = next_val;
	if (*stack)
		(*stack)->prev = NULL;
}
