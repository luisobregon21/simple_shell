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
	int flag = 1;
	char *input;
	char **user_input = NULL;
	char **path = path_to_arr(env);

	while (flag)
	{
		if (!isatty(STDIN_FILENO))
		{
			flag = 0;
		}
		else
		{
			_putchar('$');
			_putchar(' ');
		}

		input = userinput();
		if (input == NULL)
			continue;

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
	}
	/*we need to free something here methinks*/
	//memclean(path);
	return (0);
}
