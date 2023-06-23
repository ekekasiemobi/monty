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

	if (mont->arr[1] == NULL || !is_digit(mont->arr[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		free_array();
		fclose(mont->file);
		free(mont);
		exit(EXIT_FAILURE);
	}
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
/**
 * is_digit - checks if the command is a digit
 * @c: a single pointer
 * Return: return an integer
 */

int is_digit(char *c)
{
	int i = 0;

	if (c[0] == '-')
		i = 1;

	while (c[i] != '\0')
	{
		if (!isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * find_entry - let program discover entry point
 * @stack: a stack node list
 * @line_number: opcode line number
 */
void find_entry(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	if (strcmp(mont->arr[0], "queue") == 0)
		mont->entry = 1;
	else
		mont->entry = 0;
}

/**
 * add_stack_end - add node to the end of list
 * @stack: a stack pointer
 * @line_number: opcode line number
 */
void add_stack_end(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *current;
	int num;

	if (mont->arr[1] == NULL || !is_digit(mont->arr[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		free_array();
		fclose(mont->file);
		free(mont);
		exit(EXIT_FAILURE);
	}
	num = (int) atoi(mont->arr[1]);
	current = *stack;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		malloc_error();
	new_node->n = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		while (current && current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}
