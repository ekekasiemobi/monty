#include "monty.h"
/**
 * tokenizer - tokenizer the command in file
 * @arr: argument vector
 * @read: size of token
 * @cmd: command
 */
void tokenizer(char *cmd, char ***arr, ssize_t read)
{
	char *copy_read, *delim = " $\t\n";
	int count = 0, i;

	copy_read = malloc(sizeof(char) * read);
	strcpy(copy_read, buffer);
	token = strtok(NULL, buffer);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		count++;
	}
	*arr = malloc(sizeof(char *) * (count + 1));
	if (!*arr)
		print_error("Error: malloc failed");
	token = strtok(buffer, delim);
	for (count = 0; token != NULL; count++)
	{
		(*arr)[count] = malloc(sizeof(char) * _strlen(token));
		if (!(*arr)[count])
		{
			for (i = 0 i < count; i++)
				free((*arr)[i]);
			free(*arr);
			free(copy_read);
		}
		strcpy((*arr)[count], token);
		token = strtok(NULL, delim);
	}
	(*arr)[count] = NULL;
}
