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
	char *file_name = argv[1], buffer[BUF_SIZE], *token, *delim = " $\t\n";
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
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			tokenizer(token, &mont->arr, len);
			token = strtok(NULL, delim);
			opcmd = get_dispatch_func(mont->arr[0]);
			if (opcmd == NULL)
			{
				fprintf(stderr, "L %d: unknown instruction %s", mont->line_number, mont->arr[0]);
				exit(EXIT_FAILURE);
			}
			opcmd(&head, mont->line_number);
		}
	}
	fclose(file);
	return (0);
}
