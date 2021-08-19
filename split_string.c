#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * just convert this function to work for any string...
 *
 *
 */
char **split_string(char *input)
{
	// rmove the test
	char string[] = "Johanne is lorca's sugar mama";
	//give more descripted names
	char *doge = NULL;
	char **doge_array = NULL;
	//don't really need count, strtok finds the spaces for you
	int idx, count = 0, lenght = 0;

	for (idx = 0; string[idx] != '\0'; idx++)
	{
		if (string[idx] == ' ')
		{
			count++;
		}
	}

	doge_array = malloc(sizeof(char *) * (count + 2));
	doge = strtok(string, " ");

	for (idx = 0; doge != NULL; idx++)
	{
		// we can't use strlen... make own _strlen
		lenght = strlen(doge);
		doge_array[idx] = malloc(sizeof(char) * (lenght + 1));
	/* printf("Iteration # <%d>", idx);*/
		doge_array[idx] = doge;
		doge = strtok(NULL, " ");
	}
	doge_array[idx + 1] = NULL;

/*	printf("Doge: <%s>\nIndex: <%d>", doge_array[idx], idx);
	doge_array[idx] = NULL;*/

	for (idx = 0; doge_array[idx] != NULL; idx++)
	{
		//cant use printf
		printf("%s\n", doge_array[idx]);
	}
	return (0);
}
