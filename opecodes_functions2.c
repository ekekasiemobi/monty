#include "monty.h"
/**
 * div - sub two values in a stack
 * @stack: a stack pointer
 * @line_number: a line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int num = 0;
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		free_array();
		fclose(mont->file);
		free(mont);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->next->n;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		free_array();
		fclose(mont->file);
		free(mont);
		exit(EXIT_FAILURE);
	}
	num /= (*stack)->n;
	(*stack)->next->n = num;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack)
		(*stack)->prev = NULL;
}
