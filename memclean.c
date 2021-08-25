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
	}
	free(arr);
}
