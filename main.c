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
	int flag = 0;
	char *input;
	char **user_input = NULL;
	char **path = NULL;
	(void) ac;

	do {
		flag = attycheck(flag);
		input = userinput();
		if (input == NULL)
			continue;

		if (_strncmp(input, "exit", 4) == 0)
		{
			safe_free(&input);
			exit(0);
		}
		else if (_strncmp(input, "env", 3) == 0)
		{
			envprinter(env);
			safe_free(&input);
		}
		else
		{
			user_input = split_string(input);
			path = path_to_arr(env);
			input_validator(user_input, path);
			safe_free(&input);
			memclean(user_input);
		}
		if (flag == 0)
			memclean(path);
	} while (flag);
	return (0);
}
/**
 * attycheck - checks for interactive and non-interactive mode.
 * @flag: turns off flag.
 * Return: wether flag turns on or off.
 */
int attycheck(int flag)
{
	if (!isatty(STDIN_FILENO))
	{
		flag = 0;
	}
	else
	{
		flag = 1;
		_putchar('$');
		_putchar(' ');
	}

	return (flag);
}
