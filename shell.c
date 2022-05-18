#include "main.h"

/**
  * main - A super simple shell.
  * @argc: Argument count.
  * @argv:  Argument vector.
  *
  * Description: Runs Commands with their full path without
  * any argument.
  * Return: Always 0.
  */
int main(int argc, char **argv)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL, *name = *(argv + 0);
	int i;

	if (isatty(STDIN_FILENO) == 1)
	{
		_putchar('$');
		_putchar(' ');
		/*printf("$ ");*/
	}
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		*(argv + 0) = line;
		*(line + (read - 1)) = '\0';
		exit_b(line);
		env_b(line, argc, argv);
		for (i = 0; *(line + i); i++)
		{
			if (*(line + i) == ' ')/*spaces*/
			{
				*(line + i) = '\0';
				*(argv + argc) = line + (i + 1);
				argc++;
			}
		}
		*(argv + argc) = 0;
		if (**(argv + 0))
		{
			i = checkfile(name, *(argv + 0));
			if (i != 1)
				create_child(*(argv + 0), argv);
			else
				global_exec(name, argv);
		}
		if (isatty(STDIN_FILENO) == 1)
		{
			_putchar('$');/*printf("$ ");*/
			_putchar(' ');
		}
	}
	if (isatty(STDIN_FILENO) == 1)
		_putchar('\n');/*printf("\n");*/
	free(line);
	return (0);
}

/**
  * global_exec - Executes binary files globaly.
  * @name: Name of executing file.
  * @argv: Argument Vector.
  *
  * Description: File is executed if it is found within a PATH directory.
  */
void global_exec(char *name, char **argv)
{
	int i = 0, err;
	char *path = getenv("PATH"), *npath;
	l_path *head, *node;

	head = linked_path(path);
	node = head;

	while (node)
	{
		npath = path_cat(node->pathl, *(argv + 0));
		if (npath)
		{
			err = checkfile(name, npath);
			if (err != 1)
			{
				i = 1;
				break;
			}
			else
			{
				free(npath);
				node = node->next;
			}
		}
	}
	if (i == 1)
	{
		create_child(npath, argv);
		free(npath);
	}
	else
	{
		perror(name);
		/*dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", name, argv[0]);*/
	}

	free_list(head);
}

/**
  * create_child - Creates a child process.
  * @name: Name of executing file.
  * @argv: Argument vector.
  */
void create_child(char *name, char **argv)
{
	int status;
	pid_t child = fork();

	if (child == -1)
		perror(name);
	else if (child > 0)
		waitpid(child, &status, 0);
	else if (execve(name, argv, environ) == -1)
		perror(name);

}

/**
  * path_cat - Concatenate paths.
  * @dest: Destination path.
  * @src: Source path.
  *
  * Return: Pointer to dest path.
  */
char *path_cat(char *dest, char *src)
{
	int i, len = strlen(dest) + strlen(src) + 1;
	char *ptr = malloc(len * sizeof(char));

	if (ptr == 0 || !dest || !src)
		return (0);
	for (i = 0; *dest; dest++, i++)
		*(ptr + i) = *dest;
	*(ptr + i) = '/';
	i++;
	for (; *src; i++, src++)
		*(ptr + i) = *src;
	*(ptr + i) = '\0';
	return (ptr);
}
