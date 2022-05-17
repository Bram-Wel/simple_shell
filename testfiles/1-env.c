#include "main.h"

/**
  * main - Prints addresses of envp and environ
  * variables.
  * @argc: Argument count.
  * @argv: Argument vector.
  * @envp: Environment Pointer.
  *
  * Return: Always 0.
  */
int main(__attribute__((unused))int argc, char **argv, char **envp)
{
	extern char **environ;

	(void)argv;

	printf("envp: %p\nenviron: %p\n", *envp, *environ);

	return (0);
}
