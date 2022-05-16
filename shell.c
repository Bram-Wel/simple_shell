#include "main.h"

/**
  * main - A super simple shell.
  * @argc: Argument count.
  * @argv:  Argument vector.
  *
  * Description: Runs Commands with their full path without
  * any argument.
  * Return: Always 0.
  */
int main(int argc, char **argv)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL;
	pid_t child;
	int status;

	(void)argc;
	printf("#cisfun$ ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		*(argv + 0) = line;
		*(line + (read - 1)) = '\0';
		if (strcmp(line, "exit") == 0)
		{
			kill(0, SIGCHLD);
			exit(EXIT_SUCCESS);
		}

		if (*line)
		{
			child = fork();
			if (child == -1)
				perror("Error");
			else if (child > 0)
				waitpid(child, &status, 0);
			else if (execve(*(argv + 0), argv, NULL) == -1)
				perror("Error");
		}
		printf("#cisfun$ ");
	}
	printf("\n");
	free(line);
	return (0);
}
