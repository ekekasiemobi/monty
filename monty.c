#include "monty.h"
/**
 * main - Monty byte cocde compiler
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 onerror otherwise 0;
 */
int main(int argc, char *argv[])
{
	line = 1;
	stack_t *head = NULL;
	int fd;
	char *file = argv[1], buffer[BUF_SIZE], **arr, *token;
	char *delim = " $\t\n";
	ssize_t numRead;
	void (*opcmd)(stack_t**, unsigned int);

	if (argc != 2)
		print_error("Usage: monty file", NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't open", file);
	numRead = read(fd, buffer, BUF_SIZE);
	if (numRead == -1)
		print_error("Error: Can't read", file);
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		tokenizer(token, &arr, numRead);
		token = strtok(NULL, delim);
		opcmd = get_dispatch_func(arr[0]);
		if (opcmd == NULL)
		{
			dprintf(2, "L %d: unknown instruction %s", line, arr[0]);
			exit(EXIT_FAILURE);
		}
		opcmd(&head, line);
		line++;
	}
	if (close(fd) == -1)
		print_error("Error: Can't close file", file);
	return (0);
}
