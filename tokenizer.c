#include "monty.h"
/**
 * tokenizer - tokenizer the command in file
 * @read: size of token
 * @cmd: command
 */
void tokenizer(char *cmd, ssize_t read)
{
	char *copy_cmd, *delim = " \t\n", *token;
	int count = 0, i;

	copy_cmd = malloc(sizeof(char) * read + 1);
	if (!copy_cmd)
		malloc_error();
	strcpy(copy_cmd, cmd);
	token = strtok(copy_cmd, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	mont->arr = malloc(sizeof(char *) * (count + 2));
	if (!mont->arr)
	{
		free(copy_cmd);
		malloc_error();
	}
	token = strtok(cmd, delim);
	for (count = 0; token != NULL; count++)
	{
		mont->arr[count] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!mont->arr[count])
		{
			for (i = 0; i < count; i++)
				free(mont->arr[i]);
			free(mont->arr);
			mont->arr = NULL;
			free(copy_cmd);
			malloc_error();
		}
		strcpy(mont->arr[count], token);
		mont->n += 1;
		token = strtok(NULL, delim);
	}
	mont->arr[count] = NULL;
	mont->arr[++count] = NULL;
	free(copy_cmd);
}
