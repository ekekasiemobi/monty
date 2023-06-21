#include "monty.h"
/**
 * add_stack_beg - add a new node at the beginning of a list
 * @stack: a struct node pointer to the list
 * @line_number: data to enter the list
 * Return: an update linked list
 */
void add_stack_beg(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num;

	if (mont->arr[1] != NULL && is_digit(mont->arr[1]) != 1)
	{
		num = (int) atoi(mont->arr[1]);
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
			malloc_error();
		new_node->n = num;
		if (*stack == NULL)
		{
			new_node->prev = NULL;
			new_node->next = NULL;
		}
		else
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
		}
		*stack = new_node;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		free_array();
		fclose(mont->file);
		free(mont);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_digit - checks if the command is a digit
 * @c: a single pointer
 * Return: return an integer
 */

int is_digit(char *c)
{
	int i = 0;

	while (c[i] != '\0')
	{
		if (c[i] >= '0' && c[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}
