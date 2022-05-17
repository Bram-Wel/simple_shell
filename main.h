#ifndef MAIN_H

#define MAIN_H

/*#pargma once*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>

extern char **environ;

char **strtok_f(char *str);
char *_getenv(const char *name);
void print_path_dirs(char *path);
int checkfile(char *name, char *argv);
void create_child(char *name, char **argv);
char *path_cat(char *dest, char *src);

/**
  * struct l_path - Structure storing PATH directories.
  * @pathl: A directory in the PATH variable.
  * @next: The next directory in the path variable.
  */
typedef struct l_path
{
	char *pathl;
	struct l_path *next;
} l_path;

l_path *linked_path(char *path);
void free_list(l_path *head);
int _setenv(const char *name, const char *value, int overwrite);
void global_exec(char *name, char **argv);

#endif /* #ifndef MAIN_H*/
