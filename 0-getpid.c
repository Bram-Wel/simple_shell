#include "main.h"

/**
  * main - PPID
  *
  * Return: Always 0.
  */
int main(void)
{
	pid_t ppid = getppid();

	printf("PPID: %u\n", ppid);
	return (0);
}
