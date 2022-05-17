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
	int i = 1;
	struct stat buff;

/*	if (argc < 2)
 *	{
 *		perror("Usage: _which filename ...");
 *		exit(EXIT_FAILURE);
 *	}
 */
	while (argv)/*while (*(argv + i))*/
	{
		if (stat(argv, &buff) == 0)
		{
			return (0); /*Printf("%s: Found")*/
		}
		else
		{
			dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", name, argv);
			return (1);
		}
		i++;
	}

	return (0);/*exit(EXIT_SUCCESS);*/
}
