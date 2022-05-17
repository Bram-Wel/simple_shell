#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

char **strtok_f(char *str);
char *_getenv(const char *name);
void print_path_dirs(char *path);

/**
  * struct l_path - Structure storing PATH directories.
  * @pathl: A directory in the PATH variable.
  * @next: The next directory in the pah variable.
  */
typedef struct l_path
{
	char *pathl;
	struct l_path *next;
} l_path;

l_path *linked_path(char *path);
int _setenv(const char *name, const char *value, int overwrite);
