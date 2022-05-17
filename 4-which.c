#include "main.h"

/***
 * * main - Look for files in current PATH.
 * *
 * * Return: Akways 0.
 * *\/
 * int main(int argc, char **argv){}
 */

/**
  * checkfile - check that a file exists.
  * @argv: Pointer to filename/path to file.
  *
  * Return: 0 on success, or 1 on failure.
  */
int checkfile(char *name, char *argv)
{
	/*int i = 1;*/
	struct stat buff;

	(void)name;
/*	if (argc < 2)
 *	{
 *		perror("Usage: _which filename ...");
 *		exit(EXIT_FAILURE);
 *	}
 */
	if (argv) /*while (*(argv + i))*/
	{
		/*Debug: printf("argv: %s\n", argv);*/
		if (stat(argv, &buff) == 0)/*printf("%s: Found\n", argv);*/
			return (0);
		/*if ()
			dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", name, argv);
		i++;*/
	}

	return (1);/*exit(EXIT_SUCCESS);*/
}
