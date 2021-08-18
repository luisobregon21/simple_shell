#include "shell.h"
/**
 * main - executes commands based on user input.
 * Return: 0 on success.
 */

int main(void)
{
	int exit = 1;
	char *input;

	while (exit)
	{
		_putchar('$');
		_putchar(':');
		input = userinput();
		/* adding string compare*/
		if (_strcmp(input, "exit") == 0)
		{
			exit = 0;
			return (0);
		}
	}
	return (0);
}
