#include "shell.h"

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	path_to_arr(env);
	return(0);
}
