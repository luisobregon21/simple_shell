#include "shell.h"

/**
 * main - executes commands based on user input
 * @ac: unused
 * @av: unused
 * @env: enviroment
 * Return: 0 on success.
 */

int main(int ac, char **av __attribute__((unused)), char **env)
{
	(void) ac;
	int exit = 1;
	char *input;
	char **user_input = NULL;
	char **path = path_to_arr(env);

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

		if (_strncmp(input, "exit", 4) == 0)
		{
			exit = 0;
			return (0);
		}
		else if (_strncmp(input, "env", 3) == 0)
		{
			envprinter(env);
		}
		else
		{
			user_input = split_string(input);
			input_validator(user_input, path);
		}
	}
	return (0);
}
