#include "monty.h"
/**
 * main - Monty byte cocde compiler
 * @argc: argument counter
 * @argv: argument vector
 * Return: an integer value 1 onerror otherwise 0;
 */
int main(int argc, char *argv[])
{
	stack_t *head;
	FILE *file;
	char *file_name = argv[1], buffer[BUF_SIZE];
	size_t len = 0;
	void (*opcmd)(stack_t**, unsigned int);

	head = NULL;
	initialize();
	if (argc != 2)
		print_error("Usage: monty file", NULL);
	file = fopen(file_name, "r");
	if (!file)
		print_error("Error: Can't open", file_name);
	while (fgets(buffer, BUF_SIZE, file) != NULL)
	{
		len = strlen(buffer);
		if (buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
			len--;
		}
		tokenizer(buffer, &mont->arr, len);
		opcmd = get_dispatch_func(mont->arr[0]);
		if (opcmd == NULL)
			print_line_number(mont->line_number);
		opcmd(&head, mont->line_number);
		mont->line_number += 1;
		free_array();
	}
	free_stack(&head);
	fclose(file);
	return (0);
}
