/**
 * print_all - prints all the values on stack from top to the last
 *
 * @line_count: number of lines counted
 * @stack: pointer to stack to print`
 */
void print_all(stack_t **stack, unsigned int line_count)
{
	stack_t *new;
	(void)line_count;

	new = *stack;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
