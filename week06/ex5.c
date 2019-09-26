#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	int pid = fork();
	if(pid > 0)	// in parent
	{
		sleep(10);
		kill(pid, SIGTERM);
	}
	else		// in child
	{
		while(1)
		{
			sleep(1);
			printf("I'm alive! :D\n");
		}
	}

	return 0;
}