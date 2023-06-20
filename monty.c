#include "monty.h"
/**
 * main - Monty byte cocde compiler
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 onerror otherwise 0;
 */
int main(int argc, char *argv[])
{
	int fd;
	char *file = argv[1], *delimeter = " $\t\n", buffer[BUF_SIZE], **arr;
	ssize_t numRead;
	void (*table[])(stack_t**, unsigned int) = {
		{"push", add_stack_beg},
		{"pop", delete_stack},
		{"pint", print_int},
		{"pall", print_all},
		{NULL, NULL}
	};
	
	if (argc != 2)
		print_error("Usage: monty file");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't open", file);
	numRead = read(fd, buffer, BUF_SIZE);
	if (numRead == -1)
		print_error("Error: Can't read", file);
	tokenizer(&arr, buffer, numRead);
	if (close(fd) == -1)
		print_error("Error: Can't close file", file);
	return (0);
}
