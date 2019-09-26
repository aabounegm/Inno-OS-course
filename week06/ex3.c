#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigint(int sig)
{
	printf("\nCaught a SIGINT (%d)! Exiting gracefully...\n", sig);
	exit(sig);
}

int main()
{
	printf("Doing a lot of useless processing. Use CTRL+C to stop\n");

	signal(SIGINT, handle_sigint);
	
	while(1);
	return 0;
}