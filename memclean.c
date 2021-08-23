#include "shell.h"
/**
 * freer - frees up memory
 * @arr: 2D arry to be freed
 */

void memclean(char **arr)
{
	int i;
	for (i = 0; arr[i] != NULL; i++)
	{
		printf("free %i times\n", i);
		free(arr[i]);
	}
	free(arr);
}
