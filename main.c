#include "shell.h"
/*void EOF_handler(char **path, char *input)
{
	free(input);
	memclean(path);
}*/
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
	char **path = path_to_arr(env);
	(void) ac;

	do
	{
		flag = attycheck(flag, path);
		input = userinput();
		if (input == NULL)
			continue;

		/*signal(SIGQUIT, EOF_handler(path, input));*/

		if (_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			memclean(path);
			exit(0);
		}
		else if (_strncmp(input, "env", 3) == 0)
		{
			envprinter(env);
			free(input);
		}
		else
		{
			user_input = split_string(input);
			input_validator(user_input, path);
			free(input);
			memclean(user_input);
		}
	} while (flag);

	return (0);
}
/**
 * attycheck - checks for interactive and non-interactive mode.
 * @flag: turns off flag.
 * Return: wether flag turns on or off.
 */
int attycheck(int flag, char **path)
{
	if (!isatty(STDIN_FILENO))
	{
		flag = 0;
		memclean(path);
		return (flag);
	}
	else
	{
		flag = 1;
		_putchar('$');
		_putchar(' ');
	}

	return (flag);
}
