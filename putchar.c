#include "main.h"

/**
  * _putchar - Print character to stdout.
  * @c: Character to print.
  *
  * Return: 1  on success, -1 on failure.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _puts - Prints string to stdout.
  * @str: Pointer to string.
  *
  * Return: Characters printed less '\0'.
  */
int _puts(char *str)
{
	int i;

	for (i = 0; *str != '\0'; i++, str++)
		_putchar(*str);
	_putchar('\n');
	return (i++);
}
