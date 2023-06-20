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
	dprintf(2, "%s %s\n", message, file);
	exit(EXIT_FAILURE);
}
