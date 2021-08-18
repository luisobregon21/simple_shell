#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	int exit = 1;
	size_t size = 0;
	int status, len;
	char *sentence = NULL;
	char **input;
	pid_t pid;

	while (exit)
	{
		printf("$: ");
		len = getline(&sentence, &size, stdin);
		sentence[len - 1] = '\0';
		input[0] = sentence;
		input[1] = NULL;
		pid = fork();

		//strncmp needs to be created
		if (strncmp(input[0], "exit", 4) == 0)
			exit = 0;

		if (pid == 0)
		{
			if(execve(input[0], input, NULL) == 0)
			{
				perror("Error: no esta muy bien bro");
			}
			exit(0);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
