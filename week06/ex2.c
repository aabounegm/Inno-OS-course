#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define MSG_SIZE 50

int main()
{
	char msg[MSG_SIZE] = "Hello child!";
	
	int files[2];
	
	if(pipe(files) < 0)
		return 1;
	
	int pid = fork();
	if(pid > 0)	// in parent
	{
		close(files[0]);	// no need to read. can close this file (but not neccessarily)
		write(files[1], msg, MSG_SIZE);
		close(files[1]);	// finished writing. close to send EOF
		wait(NULL);			// wait till child is done
	}
	else	// in child
	{
		close(files[1]);	// no need to write. close in this process, too (as to not hang)
		char buffer[MSG_SIZE];
		int bytes_count;
		printf("Receiving a message in the child process:\n");
		while( (bytes_count = read(files[0], buffer, MSG_SIZE)) > 0)
			printf("%s", buffer);
		printf("\n");
		if(bytes_count < 0)
			return 2;
		close(files[0]);	// finished reading
	}
	
	return 0;
}