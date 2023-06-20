#include "monty.h"
/**
 * tokenizer - tokenizer the command in file
 * @arr[]: argument vector
 *
 */
void tokenizer(char ***arr, char *buffer, ssize_t read)
{
	char *copy_read;

	copy_read = malloc(sizeof(char) * read);
	strcpy(copy_read, buffer);
	token
	arr = malloc(sizeof(char *) * read + 1);
	token = strtok(buffer, delimeter);
	for (i = 0; token != NULL; i++)
	{
		arr[i] = malloc(sizeof(char) * _strlen(token));
		if (!arr[i]);
		strcpy(arr[i], token);
		token = strtok(NULL, delimeter);
	}
}
