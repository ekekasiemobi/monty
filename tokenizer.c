#include "monty.h"
/**
 * tokenizer - tokenizer the command in file
 * @arr: argument vector
 * @read: size of token
 * @cmd: command
 */
void tokenizer(char *cmd, char ***arr, ssize_t read)
{
	char *copy_read, *delim = " $\t\n", *token;
	int count = 0, i;

	copy_read = malloc(sizeof(char) * read);
	if (!copy_read)
		malloc_error();
	strcpy(copy_read, cmd);
	token = strtok(NULL, cmd);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	*arr = malloc(sizeof(char *) * (count + 1));
	if (!*arr)
		malloc_error();
	token = strtok(cmd, delim);
	for (count = 0; token != NULL; count++)
	{
		(*arr)[count] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!(*arr)[count])
		{
			for (i = 0; i < count; i++)
				free((*arr)[i]);
			free(*arr);
			free(copy_read);
			malloc_error();
		}
		strcpy((*arr)[count], token);
		token = strtok(NULL, delim);
	}
	(*arr)[count] = NULL;
	free(copy_read);
}
