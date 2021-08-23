#include "shell.h"

/**
 *input_validator - validates if user input is an executable
 *@usr_input: 2D array with executable name and arguments
 *@path: 2D array with all the path
 */

void input_validator(char **usr_input, char **path)
{
	struct stat st;
	int i, j;
	char *full_path;

	if(stat(usr_input[0], &st) != 0)
	{
		for (i = 0; path[i] != NULL; i++)
		{
			full_path = concatenator(path[i], "/");
			full_path = concatenator(full_path, usr_input[0]);
			if(stat(full_path, &st) == 0)
			{
				usr_input[0] = full_path;
				executor(usr_input);
				return;
			}
			else
				continue;
		}
	}

	if (stat(usr_input[0], &st) == 0)
		executor(usr_input);
	else
		perror("ayy");
}
