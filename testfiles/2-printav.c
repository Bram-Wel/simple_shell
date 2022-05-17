#include "main.h"

/**
  * main - Print av.
  *
  * Return: Always 0.
  */
int main(__attribute__((unused))int argc, char **argv)
{
	int i = 1;

	while (argv[i] != 0)
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
	return (0);
}
