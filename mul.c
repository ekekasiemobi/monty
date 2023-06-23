#include "monty.h"
/**
 * mul - sub two values in a stack
 * @stack: a stack pointer
 * @line_number: a line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		free_array();
		fclose(mont->file);
		free(mont);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->next->n;
	num *= (*stack)->n;
	(*stack)->next->n = num;
	pop(stack, line_number);
}
