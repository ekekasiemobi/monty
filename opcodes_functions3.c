#include "monty.h"

/**
 * rotr - rotate to top
 * @stack: a stack list
 * @line_number: opcode line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *current;

	temp = *stack;
	current = *stack;

	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	while (current->next != NULL)
	{
		current = current->next;
	}

	temp = current->prev;
	temp->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;

}
