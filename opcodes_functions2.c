#include "monty.h"
/**
 * div - sub two values in a stack
 * @stack: a stack pointer
 * @line_number: a line number
 */
void divide(stack_t **stack, unsigned int line_number)
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

/**
 * print_mod - find the modulus of a number
 * @stack: a stack pointer
 * @line_number: command number
 */
void print_mod(stack_t **stack, unsigned int line_number)
{	
	int num = 0;
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	num %= (*stack)->n;
	(*stack)->next->n = num;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack)
		(*stack)->prev = NULL;
}


void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *value;

	value = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (value->n < 32 || value->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}


void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;

	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;
	temp = *stack;
	current = *stack;

	while (current->next != NULL)
	{
		current = current->next;
	}

	*stack = (*stack)->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;

}

