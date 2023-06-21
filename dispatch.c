#include "monty.h"
/**
 * get_dispatch_func - get the corresponding function
 * @str: opcommand
 * Return: found command index
 */
void (*get_dispatch_func(char *str))(stack_t**, unsigned int)
{
	int i = 0;
	instruction_t func[] = {
		{"add", print_add},
		{"push", add_stack_beg},
		{"pall", print_all},
		{"pint", print_int},
		{"pop", pop},
		{"nop", nop},
		{NULL, NULL}
	};

	while (func[i].opcode != NULL)
	{
		if (strcmp(func[i].opcode, str) == 0)
			return (func[i].f);
		i++;
	}
	return NULL;
}