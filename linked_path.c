#include "main.h"

/***
 * * main - Prints liked list.
 * *
 * * Return: Always 0.
 * *
 *
 * int main(void)
 * {
 *	l_path *head, *node;
 *	char *path = getenv("PATH");
 *
 *	head = linked_path(path);
 *	node = head;
 *
 *	while (node)
 *	{
 *		printf("path: %s\n", node->pathl);
 *		node = node->next;
 *	}
 *	free_list(head);
 *	return (0);
 * }
 */

/**
  * linked_path - Builds linked list of path directories.
  * @path: Path variable.
  *
  * Return: Pointer to header of linked list.
  */
l_path *linked_path(char *path)
{
	l_path *head = malloc(sizeof(l_path));
	l_path *node;
	int i, len = strlen(path) + 1;
	char *ptr = malloc(len * sizeof(char));

	if (head == 0 || ptr == 0)
		return (0);

	node = head;
	for (i = 0; *(path + i); i++)
	{
		*(ptr + i) = *(path + i);
		if (*(path + i) == ':')
		{
			*(ptr + i) = '\0';
			node->pathl = ptr;
		}
	}
	for (; *path; path++)
	{
		ptr++;
		if (*path == ':')
		{
			node->next = malloc(sizeof(l_path));
			if (node->next == 0)
				return (0);
			node = node->next;
			node->pathl = ptr;
		}
	}
	return (head);
}

/**
  * free_list - Frees a built linked list.
  * @head: Pointer to linked list.
  */
void free_list(l_path *head)
{
	l_path *node;

	if (head)
		free(head->pathl);

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
