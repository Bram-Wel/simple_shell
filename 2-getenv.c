#include "main.h"

/***
 * * main - Prints an environment variable.
 * *
 * * Return: Always 0;
 * *
 * int main(void)
 * {
 *	printf("PATH: %s\n", _getenv("PATH"));
 *	printf("null: %s\n", _getenv("shit"));
 *	return (0);
 *}
 */

/**
  * _getenv - Obtains an environment variable.
  * @name: The environment varible by NAME.
  *
  * Return: Pointer to the environment variable.
  */
char *_getenv(const char *name)
{
	int i = 0;
	char *p = NULL;

	for (; *(environ + i); i++)
	{
		if (**(environ + i) == *name)
		{
			p = *(environ + i);
			while (*name)
			{
				name++;
				p++;
			}
			p++;
			return (p);
		}
	}
	return (p);
}
