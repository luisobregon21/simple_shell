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
	int len1, len2, sum;
	char *concat;

	len1 = _strlen(path);
	len2 = _strlen(userinput);
	sum = len1 + len2;

	concat = malloc(sizeof(char) * (sum + 1));


	for (len1 = 0; path[len1] != '\0'; len1++)
	{
		concat[len1] = path[len1];
	}

	for (len2 = 0; userinput[len2] != '\0'; len2++)
	{
		concat[len1] = userinput[len2];
		len1++;
	}
	concat[sum] = '\0';
	return (concat);
}
