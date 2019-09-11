#include <stdio.h>
#include <unistd.h>

int main()
{
	/*
	 * Calling fork() returns the PID of the child process to the parent, and 0 to the child
	 * getpid() function will return the PID of the process in which it was called
	 * The PID increases by 1 for each new process
	 */
	int n = fork();
	char *processName = (n != 0) ? "parent" : "child ";
	printf("Hello from %s [%d - %d]\n", processName, getpid(), n);
	return 0;
}