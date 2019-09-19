#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* arg)
{
	printf("This is thread #%lu\n", *(unsigned long*)arg);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int N=5;
	if(argc == 2)
		N = strtol(argv[1], NULL, 10);
	
	for(int i=1; i<=N; i++)
	{
		pthread_t thread_id;
		pthread_create(&thread_id, NULL, thread_func, &thread_id);
		printf("Created thread #%lu\n", thread_id);
		/*
		 * Will wait until the thread exits to create the new one.
		 * The ID printed is the same for all of them, 
		    since the previous one exited and the ID can be reused
		 */
		pthread_join(thread_id, NULL);	// Addition to ex1.1
	}	
	return 0;
}