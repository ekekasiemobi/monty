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
		{"add", print_add}, {"pall", pall},
		{"push", push_stack}, {"pint", print_int},
		{"queue", find_entry}, {"stack", find_entry},
		{"pop", pop}, {"nop", nop},
		{"swap", swap}, {"div", divide},
		{"sub", sub}, {"mod", print_mod},
		{"mul", mul}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL}
	};

	while (func[i].opcode != NULL)
	{
		if (strcmp(func[i].opcode, str) == 0)
			return (func[i].f);
		i++;
	}
	return (NULL);
}
