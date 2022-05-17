#include "main.h"

/**
  * main - Sets an environment variable.
  *
  * Return: Always 0.
  */
int main(void)
{
	char *name = "me", *value = "ok";
	int e = _setenv(name, value, 0);

	return (e);
}

/**
  * _setenv - Changes / Adds an environment variable.
  * @name: Variable name.
  * @value: Value of env variable.
  * @overwrite: Determines to overwrite VALUE if varable exists.
  *
  * Description: Environment variable is of the form
  * NAME=VALUE.
  * Return: 0 on Success, or -1 on error.
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, len = 0, j;
	char *val = getenv(name), **env;

	if (val)
	{
		if (overwrite == 0)
			return (0);
		if (overwrite != 0)
		{
			while (*(value + i))
			{
				*(val + i) = *(value + i);
				i++;
			}
		}
	}
	else
	{
		for (; *(environ + len); len++)
			;
		len++;
		env = malloc(len * sizeof(char *));
		if (env == 0)
			return (-1);

		for (i = 0; i < len; i++)
		{
			j = strlen(*(environ + i)) + 1;
			*(env + i) = malloc(j * sizeof(char));
			if (*(env + i) == 0)
				return (-1);
			if (*(environ + i))
			{
				memcpy(*(env + i), *(environ + i), (size_t)j);
			}
			else
			{
			j = strlen(val) + 1;
			memcpy(*(env + i), val, (size_t)j);
			}
		}
	}
	return (0);
}
