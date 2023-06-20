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
