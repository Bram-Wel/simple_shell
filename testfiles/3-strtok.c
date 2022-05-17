#include "main.h"

/**
  * main - String spliter.
  *
  * Return: Always 0.
  */
int main(void)
{
	char *str = "Okay. Here is sth.";
	char **arr = strtok_f(str);
	int i = 0;
	while ((strcmp(*(arr + i), "sth.") != 0))
	{
		printf("Words: %s\n", *(arr + i));
		i++;
	}
	printf("Words: %s\n", *(arr + i));

	free(arr);
	return (0);
}

/**
  * strtok_f - Splits a string.
  * @str: String to be split.
  *
  * Return: Array of each word in the string.
  */
char **strtok_f(char *str)
{
	int i = 0, len = strlen(str);
	char *token, *strc = malloc((len + 1) * sizeof(char));
	char **str_arr = malloc((len + 1) * sizeof(char));

	strc = strcpy(strc, str);
	printf("Debug: strc: %s\n", strc);
	token = strtok(strc, " ");

	while (token != 0)
	{
		*(str_arr + i) = token;
		token = strtok(NULL, " ");
		i++;
	}
/*	free(strc);
*/	return (str_arr);
}
