#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
	int files[2];
	if(pipe(files) < 0)
		return 1;
	int pid1 = fork();
	if(pid1 > 0)	// in parent
	{
		printf("[Parent ]: Forked 1st child (id: %d)\n", pid1);
		sleep(2);
		int pid2 = fork();
		if(pid2 > 0)	// still parent
		{
			printf("[Parent ]: Forked 2nd child (id: %d)\n", pid2);
			write(files[1], &pid2, sizeof(int));	// Send the pid to the 1st child
			close(files[1]);					// finished writing. close to send EOF
			int status;
			waitpid(pid2, &status, WUNTRACED);
			printf("[Parent ]: Child 2 with PID %d signaled: %d\n", pid2, status);			
			
			wait(NULL);			// wait till children are done
		}
		else	// 2nd child
		{
			printf("[Child 2]: The weather is so cold. I think I'll *freeze* ;)\n");
			sleep(3);	//  enough time for child 1 to stop it
			printf("[Child 2]: I'm back :D\n");
		}
	}
	else		// in child 1
	{
		close(files[1]);
		printf("[Child 1]: Waiting for child 2 PID\n");
		int pid;
		if(read(files[0], &pid, sizeof(int)) < 0)
			return -1;
		close(files[0]);
		sleep(2);
		printf("[Child 1]: Got the pid (%d)! Now stopping it\n", pid);
		kill(pid, SIGSTOP);
		sleep(6);
		printf("[Child 1]: Alright. I'll let it continue :)\n");
		kill(pid, SIGCONT);
	}
	return 0;
}