#include "shell.h"

int main(void)
{
	char s[100] = "Hola ";
	char *s2 = "que tal?";
	char *s3;
	s3 = concatenator(s, s2);
	printf("%s\n", s3);
	return (0);

}
