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
	char *line = NULL, *name = *(argv + 0);
	int i;

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

		for (i = 0; *(line + i); i++)
		{
			if (*(line + i) == ' ')
			{
				*(line + i) = '\0';
				*(argv + argc) = line + (i + 1);
				argc++;
			}
		}
		*(argv + argc) = 0;

		if (**(argv + 0))
		{
			i = checkfile(name, *(argv + 0));
			if (i != 1)
				create_child(*(argv + 0), argv);
		}
		printf("#cisfun$ ");
	}
	printf("\n");
	free(line);
	return (0);
}

/**
  * create_child - Creates a child process.
  * @name: Name of executing file.
  * @argv: Argument vector.
  */
void create_child(char *name, char **argv)
{
	int status;
	pid_t child = fork();

	if (child == -1)
		perror(name);
	else if (child > 0)
		waitpid(child, &status, 0);
	else if (execve(name, argv, environ) == -1)
		perror(name);

}
