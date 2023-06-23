#include "monty.h"

/**
 * pall - prints all the values on stack from top to the last
 * @stack: pointer to stack to print`
 * @line_number: number of lines counted
 */
void pall(stack_t **stack, unsigned int line_number)
{
	print_all(stack, line_number);
}

/**
 * print_all - prints all the values on stack from top to the last
 *
 * @stack: pointer to stack to print`
 * @line_number: number of lines counted
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	if (!stack || !(*stack))
		return;
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
 * @stack: pointer to stack to print
 * @line_number: number of lines counted
 */
void print_int(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * print_add - adds two elements of the stack
 *
 * @stack: pointer to stack to print
 * @line_number: number of lines in the stack
 */

void print_add(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->next->n;
	num += (*stack)->n;
	(*stack)->next->n = num;
	pop(stack, line_number);
}


/**
 * nop - function does nothing
 *
 * @stack: pointer to stacck to print
 * @line_number: number of lines counted
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
