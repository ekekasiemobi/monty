#include "monty.h"
/**
 * get_dispatch_func - get the corresponding function
 * @str: opcommand
 * Return: found command index
 */
int (*get_dispatch_func(char *str))(stack_t**, unsigned int)
{
	int i = 0;
	instruction_t func[] = {
		{"push", add_stack_beg},
		{"pop", delete_stack},
		{"pint", print_int},
		{"pall", print_all},
		{NULL, NULL}
	};

	while (i < 5)
	{
		if (func[i].opcode[0] == str[0])
			return (func[i].f);
		i++;
	}
	return (NULL);
}
