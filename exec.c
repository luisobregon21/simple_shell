#include "shell.h"

/**
 * executor - recieves user input and executes
 * @user_input - two dimensional array with executable name and arguments
 *
 */

void executor(char **user_input)
{
	int child;

	child = fork();
	if (child == 0)
	{
		if(execve(user_input[0], user_input, NULL) == -1)
		{
			perror("Error: this sheit ain't no working m8");
		}
	}
}
