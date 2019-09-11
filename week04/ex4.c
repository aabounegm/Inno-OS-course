#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char command[100];
	printf("Hint: use command \"exit\" to exit the program\n");
	while(strcmp(command, "exit\n"))
	{
		fgets(command, 100, stdin);
		if (fork() == 0) {
			system(command);
			break;
		}
	}
	return 0;
}