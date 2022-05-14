#include "main.h"

/**
  * main - A super simple shell.
  *
  * Description: Runs Commands with their full path without
  * any argument.
  * Return: Always 0.
  */
int main(void)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL, *argv[] = {"", NULL};
	pid_t child;
	int status;

	printf("#cisfun$ ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		*(argv + 0) = line;
		printf("Debug: %s Size: %lu Read: %lu\n", *(argv + 0), strlen(line), read);
		*(line + (read - 1)) = '\0';
		child = fork();
		if (child == -1)
			perror("Error");
		else if (child > 0)
			waitpid(child, &status, 0);
		else if (execve(*(argv + 0), argv, NULL) == -1)
			perror("Error");
		printf("#cisfun$ ");
	}
	printf("\n");
	free(line);
	return (0);
}
