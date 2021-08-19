#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/**
 *this main checks if argv[1] is an executable with stat
 *parses through the enviroment
 *finds the path
 *tokenizes the path into a 2d array
 *checks if argv[1] is exec, if not
 *concats every single element in the 2d array with what's passed in argv[1]
 *and checks every single one with stat
 *if we find a match we print found if not, not found
 */

int main(int ac, char **av, char **env)
{
	unsigned int i, len = 0, colons = 2;
	char *path = NULL , *token = NULL;
	char **patharray = NULL;
	//struct stat st;

	if (ac < 2)
	{
		printf("use a path to file\n");
		return(1);
	}

	/*store path into 2d array and print it*/
	for (i = 0; env[i] != NULL; i++)
	{
		/*finds PATH in enviroment*/
		if (strncmp(env[i], "PATH", 4) == 0)
			break;
	}
	/*stores that PATH long string into a string called path*/
	path = env[i];
	/*separates PATH= from the rest of the string*/
	token = strtok(path, "=");
	/*at this point token should contain PATH= and the rest of
	 * path all of the paths separated by :"
	 */
	/*I need a way to malloc the elements of patharray so it is as big as the
	 *number of Paths in PATH
	 *maybe I can use path as it is now and count the number of : in it?
	 */

	for(i = 0; token != NULL; i++)
	{
		token = strtok(NULL, ":");
		patharray[i] = malloc(sizeof(char *));
		patharray[i] = token;
	}
	patharray[i + 1] = NULL;

}
