#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char command[100];
	printf("Hint: use command \"exit\" to exit the program\n");
	while(strcmp(command, "exit"))
	{
		printf("> ");
		scanf("%100s", command);
		system(command);
	}
	return 0;
}
