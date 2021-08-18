#include "shell.h"
/**
 * main - executes commands based on user input.
 * Return: 0 on success.
 */

int main(void)
{
	char *input;
	while(1)
	{
		_putchar('$');
		_putchar(':');
		input = userinput();
	}
	return (0);
}
