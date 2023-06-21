#include "monty.h"
/**
 * print_error - Print error message to stderr
 * @message: error message
 * @file: exit status code
 */
void print_error(char *message, char *file)
{
	if (file == NULL)
		file = "";
	fprintf(stderr, "%s %s\n", message, file);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - print malloc error
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}

/**
 * print_line_number - print unknown error:
 * @line: line number
 */
void print_line_number(unsigned int line)
{
	int i;

	fprintf(stderr, "L %d: unknown instruction %s", line, mont->arr[0]);
	for (i = 0; mont->arr[i] != NULL; i++)
		free(mont->arr[i]);
	free(mont->arr);
	exit(EXIT_FAILURE);
}
