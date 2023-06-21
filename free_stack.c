#include "monty.h"
/**
 * free_stack - free stack
 * @head: a struct node pointer
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
