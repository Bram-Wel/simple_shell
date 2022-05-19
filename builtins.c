#include "main.h"

/**
  * exit_b - exits the shell.
  * @line: Line read from stdin.
  */
void exit_b(char *line)
{
	/*exit*/
	if (_strcmp(line, "exit") == 0)
	{
		kill(0, SIGCHLD);
		exit(EXIT_SUCCESS);/*127*/
	}
}

/**
  * env_b - Prints the environment.
  * @line: Line read from stdin.
  * @envp: Environment variable.
  */
void env_b(char *line, char **envp)
{
	int i;

	if (_strcmp(line, "env") == 0)
	{
		for (i = 0; envp[i] != 0; i++)
			_puts(envp[i]);/*printf("%s\n", environ[i]);*/
	}
}
