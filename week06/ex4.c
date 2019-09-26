#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig)
{
	printf("\nCaught signal %d. Handling...\n", sig);
	switch(sig)
	{
		case SIGKILL:
			printf("Killing :(\n");
			exit(sig);
		case SIGSTOP:
			printf("Stopping :/\n");
			exit(sig);
		case SIGUSR1:
			printf("Custom user signal. What should I do?\n");
			exit(sig);
		default:
			printf("Unknown signal X(\n");
			exit(sig);
	}
}

int main()
{
	printf("Send a signal to stop the program\n");

	signal(SIGKILL, handle_signal);
	signal(SIGSTOP, handle_signal);
	signal(SIGUSR1, handle_signal);
	/**
	  * SIGKILL and SIGSTOP cannot be caught.
	  * 
	  */
	
	while(1);
	return 0;
}