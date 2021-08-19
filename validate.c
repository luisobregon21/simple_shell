#include "shell.h"

/**
 *input_validator - validates if user input is an executable
 *@usr_input: 2D array with executable name and arguments
 *@path: 2D array with all the path
 */

void input_validator(char **usr_input)
{
	struct stat st;

	if(stat(usr_input[0], &st) == 0)
		executor(usr_input);
	else
		perror("command not found");
}
