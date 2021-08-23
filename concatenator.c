#include "shell.h"
/**
 * *concatenator - concatenates two strings to find the right executable path.
 * @path: the path we are completing.
 * @userinput: what the user types.
 *
 * Return: the path to be executed.
 */

char *concatenator(char *path, char *userinput)
{
	int index, index2;

	for (index = 0; path[index] != '\0'; index++)
	;

	for (index2 = 0; userinput[index2] != '\0'; index2++)
	{
		path[index] = userinput[index2];
		index++;
	}
	path[index] = '\0';
	return (path);
}
