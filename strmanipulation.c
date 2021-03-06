#include "shell.h"
/**
 * _strncmp - compares two string.
 * @s1: first string.
 * @s2: second string we are comparing.
 * @n: the number of bytes it will compare.
 * Return: 0 if the strings are the same.
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t index;

	for (index = 0; index < n && (s1[index] ==
		s2[index]) && s1[index] != '\0'; index++, n--)
	;
	return (s1[index] - s2[index]);
}
/**
 * _strlen - finds lenght of the string
 * @string: the string
 * Return: lenght of the string.
 */
int _strlen(char *string)
{
	int len = 0;

	while (string[len] != '\0')
		len++;
	return (len);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * userinput - passes user input to main.
 * Return: user input without the new line.
 */

char *userinput(void)
{
	size_t size = 0;
	char *sentence = NULL;
	int len = 0;

	len = getline(&sentence, &size, stdin);
	sentence[len - 1] = '\0';
	if (space_check(sentence) == 1)
	{
		free(sentence);
		sentence = NULL;
	}
	return (sentence);
}
/**
 * *_strcpy - function
 * @dest: parameter
 * @src: parameter
 * Return: char
 */

char *_strcpy(char *dest, char *src)
{
	int idx, len;

	len = _strlen(src);

	for (idx = 0 ; idx <= len ; idx++)
	{
		dest[idx] = src[idx];
	}

	return (dest);
}

