#include "monty.h"
/**
 * swap - swap to value in a stack
 * @stack: a stack pointer
 * @line_number: a line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
