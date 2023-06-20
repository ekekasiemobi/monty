#include "monty.h"
/**
 * main - Monty byte cocde compiler
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 onerror otherwise 0;
 */
int main(int argc, char *argv[])
{
<<<<<<< HEAD
	stack_t *head;
	int fd, line = 1;
	char *file = argv[1], buffer[BUF_SIZE], **arr,
	     *token, *delim = " $\t\n";
	ssize_t numRead;
	void (*opcmd)(stack_t**, unsigned int);

	head = NULL;
	if (argc != 2)
		print_error("Usage: monty file", NULL);
=======
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
>>>>>>> db94dcbebaa3b038cfb001aa4a2a7f981195fb2d
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't open", file);
	numRead = read(fd, buffer, BUF_SIZE);
	if (numRead == -1)
		print_error("Error: Can't read", file);
<<<<<<< HEAD
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		tokenizer(token, &arr, numRead);
		token = strtok(NULL, delim);
		opcmd = get_dispatch_func(arr[0]);
		if (opcmd == NULL)
		{
			fprintf(stderr, "L %d: unknown instruction %s", line, arr[0]);
			exit(EXIT_FAILURE);
		}
		opcmd(&head, line);
		line++;
	}
=======
	tokenizer(&arr, buffer, numRead);
>>>>>>> db94dcbebaa3b038cfb001aa4a2a7f981195fb2d
	if (close(fd) == -1)
		print_error("Error: Can't close file", file);
	return (0);
}
