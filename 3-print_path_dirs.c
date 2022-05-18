#include "main.h"

/***
 * * main - Prints path directories.
 * *
 * * Return: Always 0.
 * *
 *
 * int main(void)
 * {
 *	char *path = getenv("PATH");
 *
 *	print_path_dirs(path);
 *	return (0);
 * }
 */

/**
  * print_path_dirs - Prints the directories in PATH
  * one per line.
  * @path: PATH variable.
  */
void print_path_dirs(char *path)
{
	int i = 0;
	char *pathc = malloc(((int)_strlen(path) + 1) * sizeof(char));

	if (pathc == 0)
		return;

	for (; *(path + i); i++)
	{
		*(pathc + i) = *(path + i);
		if (*(path + i) == ':')
			*(pathc + i) = '\n';
	}
	_puts(pathc);/*printf("%s\n", pathc);*/
	free(pathc);
}

/**
  * _strlen - Finds length of string exluding '\0' byte.
  * @s: String.
  *
  * Return: Length in bytes;
  */
size_t _strlen(const char *s)
{
	size_t len = 0;

	if (s)
	{
		for (; *s != '\0'; len++)
			s++;
	}

	return (len);
}
