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
	fprintf(stderr, "%s%s\n", message, file);
	free(mont);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - print malloc error
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free(mont);
	exit(EXIT_FAILURE);
}

/**
 * print_line_number - print unknown error:
 * @line: line number
 */
void print_line_number(unsigned int line)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, mont->arr[0]);
}

