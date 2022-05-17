#define _GNU_SOURCE
#include "main.h"

/**
  * main - Prints user input line.
  *
  * Description: Compile with std=99 for the %zu => in printf.
  * But u can use %u for std=89 I think. I haven't confirmed.
  * THIS IS JUST A TEST FILE.
  * Return: Always 0.
  */
int main(void)
{
//	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

/*	fp = fopen("/etc/motd", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
*/
	printf("$ ");
	while ((read = getline(&line, &len, stdin)) != -1) {
		printf("Retrieved line of length %zu :\n", read);
		printf("%s", line);
		printf("$ ");
	}
	printf("\n");

	free(line);
	exit(EXIT_SUCCESS);
}
