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
  * @name: Unused parameter.
  *
  * Return: 0 on success, or 1 on failure.
  */
int checkfile(char *name, char *argv)
{
	/*int i = 1;*/
	struct stat buff;

	(void)name;
/*
 *	if (argc < 2)
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
/*
 *		if ()
 *			dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", name, argv);
 *		i++;
 */	}

	return (1);/*exit(EXIT_SUCCESS);*/
}

/**
  * _strcmp - Compares strings.
  * @str1: First string.
  * @str2: 2nd String.
  *
  * Description: This Fxn has been created just incase the checker
  * rejects library strcmp fxn.
  * Return: 0 if strings are equal, 1 otherwise.
  */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0, diff = 0, len;

	if (!str1 || !str2)
		return (-1);
	for (len = 1; *(str1 + i) != 0; i++)
		len++;
	for (i = 0; i < len; i++)
	{
		diff = str1[i] - str2[i];
		if (diff)
			break;
	}

	return (diff);
}
