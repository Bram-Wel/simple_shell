#include "main.h"

/**
  * exit_b - exits the shell.
  * @line: Line read from stdin.
  */
void exit_b(char *line)
{
	/*exit*/
	if (strcmp(line, "exit") == 0)
	{
		kill(0, SIGCHLD);
		exit(127);
	}
}

/**
  * env_b - Prints the environment.
  * @line: Line read from stdin.
  * @envp: Environment variable.
  * @argc: Argument Count.
  */
void env_b(char *line, int argc, char **envp)
{
	int i;

	if (strcmp(line, "env") == 0)
	{
		for (i = argc; envp[i]; i++)
			printf("%s\n", envp[i]);
		envp[i] = 0;
	}
}
