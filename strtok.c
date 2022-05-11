#include <stdio.h>
#include <string.h>

int main() {
	char string[50] = "Get in loser, we're going shopping!";

	char * token = strtok(string, " ");

	while(token != NULL){
		printf ("%s\n", token);
		token = strtok(NULL, " ");
	}
	return 0;
}

