#include "monty.h"
/**
 * add_stack_beg - add a new node at the beginning of a list
 * @stack: a struct node pointer to the list
 * @n: data to enter the list
 * Return: an update linked list
 */
void add_stack_beg(stack_t **stack, unsigned int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		malloc_error();
	new_node->n = n;
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
