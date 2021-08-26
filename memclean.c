#include "shell.h"
/**
 * memclean - frees up memory
 * @arr: 2D arry to be freed
 */

void memclean(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
}

/**
 * safe_free - free with NULL checks
 * @ptr: the element to be freed
 */
void safe_free(char **ptr)
{
	if (*ptr == NULL)
	{
		return;
	}
	else
	{
		free(*ptr);
		*ptr = NULL;
	}
}
/**
 * space_check - checks for spaces in user input
 * @sentence: user input
 * Return: 1 if only spaces
 */
int space_check(char *sentence)
{
	int i;

	for (i = 0; sentence[i] != '\0'; i++)
	{
		if (sentence[i] != 32)
			return (0);
	}
	return (1);
}
