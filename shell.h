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
//input validator function
//path finder function
char *concatenator(char *path, char *userinput);
//forking function
void executor(char **user_input);
//The freer

#endif
