#include "monty.h"
/**
 * push_stack - push element to a stack or queue
 * @stack: a stack item or queue
 * @line_number: opcode line number;
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	if (mont->entry == 0)
		add_stack_beg(stack, line_number);
	else
		add_stack_end(stack, line_number);
}
