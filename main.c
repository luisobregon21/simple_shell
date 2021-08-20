#include "shell.h"
char **split_string(char * input);
/**
 * main - executes commands based on user input.
 * Return: 0 on success.
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	int exit = 1;
	char *input;
	char **user_input = NULL;

	while (exit)
	{
		if (!isatty(STDIN_FILENO))
		{
			exit = 0;
		}
		else
		{
			_putchar('$');
			_putchar(' ');
		}

		input = userinput();
		/* adding string compare*/

		// add the n part of strncmp
		if (_strncmp(input, "exit", 4) == 0)
		{
			exit = 0;
			return (0);
		}
		/*else we convert it into a 2d arr*/
		else if (_strncmp(input, "env", 3) == 0)
		{
			envprinter(env);
		}
		else
		{
			/*
			 *convert to 2d array
			 *pass the return to our executor function
			 */
			user_input = split_string(input);
			input_validator(user_input);
		}
	}
	return (0);
}

char **split_string(char *input)
{
	char **twod_array = NULL;
	twod_array = malloc(sizeof(twod_array) * 2);
	if (twod_array == NULL)
		return (NULL);
	twod_array[0] = malloc(20);
	twod_array[1] = malloc(20);
	twod_array[0] = input;
	twod_array[1] = NULL;

	return(twod_array);
}
