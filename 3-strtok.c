#include "main.h"

/***
 * * main - String spliter.
 * *
 * * Return: Always 0.
 * *
 * int main(void)
 * {
 *	char *str = "Okay. Here is sth.";
 *	char **arr = strtok_f(str);
 *	int i = 0;
 *	while ((strcmp(*(arr + i), "sth.") != 0))
 *	{
 *		printf("Words: %s\n", *(arr + i));
 *		i++;
 *	}
 *	printf("Words: %s\n", *(arr + i));
 *
 *	free(arr);
 *	return (0);
 * }
 */

/**
  * strtok_f - Splits a string.
  * @str: String to be split.
  * @tokens: Pointer to tokens.
  */
void strtok_f(char *str, char **tokens)
{
	int i;
	char *token;

	for (token = strtok(str, " "), i = 0; token != 0; i++)
	{
	/*printf("token: %s\n*(argv + %d): %s\n", token, i, *(argv + i));*/
		*(tokens + i) = token;
		token = strtok(NULL, " ");
	}
	/*printf("envp: %s\n---\nenviron: %s\n", *envp, *environ);*/
	*(tokens + i) = token;
}
