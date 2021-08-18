#include "shell.h"
/**
 * _strcmp - compares two string.
 * @s1: first string.
 * @s2: second string we are comparing.
 *
 * Return: 0 if the strings are the same.
 * returns the difference between string one
 * and string two otherwise.
 * if string 1 is larger, the return value is positive.
 * if string 2 is larger, the return value is negative.
 */

int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; (s1[index] == s2[index]) && s1[index] != '\0'; index++)
	;
	return (s1[index] - s2[index]);
}
