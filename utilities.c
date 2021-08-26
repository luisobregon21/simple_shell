#include "shell.h"
/**
 * *split_string - Converts any string to 2D array.
 * @string: contain the user input.
 * Return: The 2D array.
 *
 */
char **split_string(char *string)
{
	char *token = NULL;
	char **token_array = NULL;
	int idx, count = 0, lenght = 0;

	for (idx = 0; string[idx] != '\0'; idx++)
	{
		if (string[idx] == ' ')
		{
			count++;
		}
	}
	count += 2;

	token_array = malloc(sizeof(char *) * count);
	if (token_array == NULL)
	{
		return (NULL);
	}
	token = strtok(string, " ");

	for (idx = 0; token != NULL; idx++)
	{
		lenght = _strlen(token);
		token_array[idx] = malloc(sizeof(char) * (lenght + 1));
		if (token_array[idx] == NULL)
		{
			return (NULL);
		}
		_strcpy(token_array[idx], token);
		token = strtok(NULL, " ");
	}
	token_array[idx] = NULL;
	return (token_array);
}
/**
 * path_to_arr - saves path in a 2d array
 * @env: the enviorement.
 * Return: the PATH in a 2d arr.
 */
char **path_to_arr(char **env)
{
	int i, count = 2, len;
	char *pathstr = NULL, *token = NULL;
	char **path = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], "PATH", 4) == 0)
			break;
	}
	pathstr = env[i];

	for (i = 0; pathstr[i] != '\0'; i++)
	{
		if (pathstr[i] == ':')
			count++;
	}
	path = malloc(sizeof(char *) * count);
	if (path == NULL)
	{
		return (NULL);
	}
	token = strtok(pathstr, "=");
	count--;
	for (i = 0; i < count; i++)
	{
		token = strtok(NULL, ":");
		len = _strlen(token);
		path[i] = malloc(sizeof(char) * (len + 1));
		if (path[i] == NULL)
		{
			return (NULL);
		}
		_strcpy(path[i], token);
	}
	path[i] = NULL;
	return (path);
}
/**
 * envprinter - prints all elements of the enviroment
 * @env: the enviroment passed.
 * @path: the path as a 2d array.
 */
void envprinter(char **env, char **path)
{
	int idx, idx2, idx3, idx4;

	for (idx = 0; env[idx] != NULL; idx++)
	{
		if (_strncmp(env[idx], "PATH", 4) == 0)
		{
			for (idx3 = 0; env[idx][idx3] != '\0'; idx3++)
			{
				_putchar(env[idx][idx3]);
			}
			_putchar('=');
			for (idx4 = 0; path[idx4] != NULL; idx4++)
			{
				for (idx3 = 0; path[idx4][idx3] != '\0'; idx3++)
				{
					_putchar(path[idx4][idx3]);
				}
				if (path[idx4 + 1] != NULL)
					_putchar(':');
			}
			_putchar('\n');
		}
		else
		{
			for (idx2 = 0; env[idx][idx2] != '\0'; idx2++)
			{
				_putchar(env[idx][idx2]);
			}
			_putchar('\n');
		}
	}
}
/**
 * *concatenator - concatenates two strings to find the right executable path.
 * @path: the path we are completing.
 * @userinput: what the user types.
 *
 * Return: the path to be executed.
 */
char *concatenator(char *path, char *userinput)
{
	int len1, len2, sum;
	char *concat;

	len1 = _strlen(path);
	len2 = _strlen(userinput);
	sum = len1 + len2;

	concat = malloc(sizeof(char) * (sum + 1));

	for (len1 = 0; path[len1] != '\0'; len1++)
	{
		concat[len1] = path[len1];
	}
	for (len2 = 0; userinput[len2] != '\0'; len2++)
	{
		concat[len1] = userinput[len2];
		len1++;
	}
	concat[sum] = '\0';
	return (concat);
}

/**
 * _strcmp - compares two string
 * @s1: first string
 * @s2: second string
 * return: 1 if match
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	for (i = 0, j = 0; s1[i] != '\0' || s2[j] != '\0'; i++, j++)
	{
		while(s1[i] == 32)
		{
			i++;
		}
		if (s1[i] != s2[j])
			return (0);
	}
	return (1);
}
