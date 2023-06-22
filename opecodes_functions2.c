#include "monty.h"


void print_div(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0;
	stack_t *temp = *stack;

	while (temp != NULL) 
	{
		length++;
		temp = temp->next;
	}

	if (length < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}
