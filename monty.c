#include "monty.h"
/**
 * main - Monty byte cocde compiler
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 onerror otherwise 0;
 */
int main(int argc, char *argv[])
{
	stact_t *head = NULL;
	int fd;
	char *file = argv[1], buffer[BUF_SIZE], **arr, delim = " $\t\n";
	ssize_t numRead;
	void (*opcmd)(stack_t**, unsigned int);

	if (argc != 2)
		print_error("Usage: monty file");
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
		opcmd = get_dispatch_func(arr[0])
		if (opcmd == NULL)
		{
			dprintf(stderr, "L %d: unknown instruction %s", line, opcode);
			exit(EXIT_FAILURE);
		}
		opcmd(&stack, arr[1]);
		line++;
	}
	if (close(fd) == -1)
		print_error("Error: Can't close file", file);
	return (0);
}
