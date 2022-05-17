#include "main.h"

/**
  * main - Look for files in current PATH.
  *
  * Return: Akways 0.
  */
int main(int argc, char **argv)
{
	int i = 1;
	struct stat buff;

	if (argc < 2)
	{
		perror("Usage: _which filename ...");
		exit(EXIT_FAILURE);
	}

	while (*(argv + i))
	{
		if (stat(*(argv + i), &buff) == 0)
			printf("%s: FOUND\n", *(argv + i));
		else
			printf("%s: NOT FOUND\n", *(argv + i));
		i++;
	}

	exit(EXIT_SUCCESS);
}
