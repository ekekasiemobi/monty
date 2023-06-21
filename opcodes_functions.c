#include "monty.h"
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
		fprintf(stderr, "L %d: can't pint, stack empty\n", line_number);
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
	stack_t *new;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	new = *stack;

	while (new->next != NULL)
	{
		new->next->n += new->n;
		new = new->next;
	}

	free(new);
}



/**
 * _nop - function does nothing
 *
 * @stack: pointer to stacck to print
 * @line_number: number of lines counted
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
