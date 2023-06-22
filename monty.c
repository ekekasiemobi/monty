#include "monty.h"
/**
 * main - Monty byte cocde compiler
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 onerror otherwise 0;
 */
param *mont;
int main(int argc, char *argv[])
{
	stack_t *head;
	char *file_name = argv[1], buffer[BUF_SIZE];
	size_t len = 0;
	void (*opcmd)(stack_t**, unsigned int);

	head = NULL;
	initialize();
	if (argc != 2)
		print_error("USAGE: monty file", NULL);
	mont->file = fopen(file_name, "r");
	if (!mont->file)
		print_error("Error: Can't open ", file_name);
	while (fgets(buffer, BUF_SIZE, mont->file) != NULL)
	{
		len = strlen(buffer);
		if (buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
			len--;
		}
		if (len == 0)
		{
			mont->line_number += 1;
			continue;
		}
		tokenizer(buffer, len);
		if (mont->arr[0] == 0)
			continue;
		opcmd = get_dispatch_func(mont->arr[0]);
		if (opcmd == NULL)
			print_line_number(mont->line_number);
		opcmd(&head, mont->line_number);
		mont->line_number += 1;
		mont->n = 0;
		free_array();
	}
	free_stack(&head);
	fclose(mont->file);
	free(mont);
	return (0);
}
