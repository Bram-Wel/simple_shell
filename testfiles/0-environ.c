#include "main.h"

/**
  * main - Prints environment variables.
  *
  * Description: Uses global variable environ instead of
  * envp argumnent to main.
  * Return: Always 0.
  */
int main(void)
{
	extern char **environ;
	int i = 0;

	for (; *(environ + i) != 0; i++)
		printf("%s\n", *(environ + i));

	return (0);
}
