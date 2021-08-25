#include "shell.h"
/**
 * executor - recieves user input and executes
 * @user_input: two dimensional array with executable name and arguments
 *
 */

void executor(char **user_input)
{
	int child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(user_input[0], user_input, NULL) == -1)
		{
			perror("not found");
			memclean(user_input);
			/*free in the main this shit*/
			exit(127);
		}
		memclean(user_input);
	}
	else
	{
		wait(&status);
	}
}

/**
 *input_validator - validates if user input is an executable
 *@usr_input: 2D array with executable name and arguments
 *@path: 2D array with all the path
 */

void input_validator(char **usr_input, char **path)
{
	struct stat st;
	int i;
	char *full_path, *first_concat;

	if (stat(usr_input[0], &st) != 0)
	{
		for (i = 0; path[i] != NULL; i++)
		{
			first_concat = concatenator(path[i], "/");
			full_path = concatenator(first_concat, usr_input[0]);
			free(first_concat);
			if (stat(full_path, &st) == 0)
			{
				_strcpy(usr_input[0], full_path);
				free(full_path);
				/*we need to free usr_input inside executor)*/
				executor(usr_input);
				return;
			}
			else
			{
				free(full_path);
				continue;
			}
		}
	}

	if (stat(usr_input[0], &st) == 0)
		executor(usr_input);
	else
	{
		/**
		 *we are missing correct output for error
		 *for non interactive
		 *it should print argv[0]: usr_input[0]: not found
		 *for interactive
		 *it should print usr_input[0]: not found
		 *we need an error handler function
		 */
		/*error_handler()*/
		/*free somthing? maybe? xD*/
		perror(usr_input[0]);
	}
}
