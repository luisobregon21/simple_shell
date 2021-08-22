#include "shell.h"

/**
 *input_validator - validates if user input is an executable
 *@usr_input: 2D array with executable name and arguments
 *@path: 2D array with all the path
 */

void input_validator(char **usr_input, char **path)
{
	struct stat st;
	int i;
	char *full_path;

	if(stat(usr_input[0], &st) == 0)
		executor(usr_input);
	/*this loop will concat / to all paths*/
	for (i = 0; path[i] != NULL; i++)
	{
		full_path = strcat(path[i], "/");
		printf("%s\n", path[i]);
	}
	
/**
	for (i = 0; path[i] != NULL; i++)
	{
		printf("path is: %s and loop nth %i\n", path[i], i);
		full_path = strcat(path[i], "/");
		full_path = strcat(full_path, usr_input[0]);
		printf("after second concat: %s\n", full_path);
		if(stat(full_path, &st) == 0)
		{
			usr_input[0] = strcpy(usr_input[0], full_path);
			printf("usr_input[%s], full_path[%s]\n", usr_input[0], full_path);
			executor(usr_input);
			printf("this is executable!\n");
		}
	}
*/
	perror("command not found");
}
