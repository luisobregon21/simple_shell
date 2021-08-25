#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

int attycheck(int flag);
int _putchar(char c);
char *userinput(void);
int _strncmp(const char *s1, const char *s2, size_t n);
void envprinter(char **env);
char **split_string(char *string);
int _strlen(char *string);
char *_strcpy(char *dest, char *src);
char **path_to_arr(char **env);
void input_validator(char **usr_input, char **path);
char *concatenator(char *path, char *userinput);
void executor(char *full_path, char **user_input);
void memclean(char **arr);
void safe_free(char **ptr);

#endif
