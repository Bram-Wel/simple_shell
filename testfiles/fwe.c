#include "main.h"

/**
  * main - executes command in 5 differnt child processes.
  *
  * Return: Always 0.
  */
int main()
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	pid_t parent = getpid(), child;
	int i = 0, status;

	while (i < 5)
	{
		printf("Parent: %u\nChild: %u\n", parent, child);
		child = fork();
		if (child == -1)
			perror("Error: Can't fork.");
		else if (child > 0)
			waitpid(child, &status, 0);
		else if (execve(argv[0], argv, NULL) == -1)
			perror("Error: Can't execve.");
		i++;
	}

	return (0);
}
