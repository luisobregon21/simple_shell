#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int _putchar(char c);
char *userinput(void);
int _strcmp(char *s1, char *s2);
//2d array converter function - Joahnne
//path finder function
void input_validator(char **usr_input); /*we need to add char **path*/
char *concatenator(char *path, char *userinput);
void executor(char **user_input);
//The freer

#endif
