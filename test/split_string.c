#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * just convert this function to work for any string...
 *
 *
 */
char **split_string(char *string)
{
	char *token = NULL;
	char **token_array = NULL;
	int idx, count = 0, lenght = 0;

	for (idx = 0; string[idx] != '\0'; idx++)
	{
		if (string[idx] == ' ')
		{
			count++;
		}
	}
	count += 2;

	token_array = malloc(sizeof(char *) * count);
	token = strtok(string, " ");

	for (idx = 0; token != NULL; idx++)
	{
		// we can't use strlen... make own _strlen
		lenght = _strlen(token);
		token_array[idx] = malloc(sizeof(char) * (lenght + 1));
		token_array[idx] = token;
		token = strtok(NULL, " ");
	}
	token_array[idx + 1] = NULL;
	return (token_array);
}
