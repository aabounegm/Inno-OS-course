#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int gcd(int a, int b)  
{
	return (a==0) ?  b : gcd(b%a, a);
}  

int lcm(int a, int b)  
{  
    return (a*b)/gcd(a, b);
}

void* thread_func(void *varargs)
{
	int *args = (int*)varargs;
	int a = args[0], b = args[1];
	int LCM = lcm(a, b);
	printf("LCM(%d, %d) = %d\n", a, b, LCM);
	free(varargs);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <file name> <thread count>\n", argv[0]);
		return 1;
	}
	
	char *filename = argv[1];
	int thread_count = strtol(argv[2], NULL, 10);
	
	FILE *input = fopen(filename, "r");

	// for holding ids of threads
	pthread_t *threads = malloc(thread_count*sizeof(pthread_t));
	
	int current_count = 0;
	while(1)
	{
		// to read the 2 arguments in an array whose lifetime extends beyond the loop iteration
		int *args = malloc(2*sizeof(int));
		
		if(fscanf(input, "%d %d", args, args+1) == EOF)
		{
			free(args);
			break;
		}
		
		// reached maximum thread_count
		if(current_count >= thread_count)
		{
			for(int i=0; i<thread_count; i++)
			{
				pthread_join(threads[i], NULL);
			}
			current_count = 0;
		}
		
		pthread_create(threads + current_count, NULL, thread_func, args);
		current_count++;
	}
	
	// wait for all remaining threads
	for(int i=0; i<thread_count; i++)
	{
		pthread_join(threads[i], NULL);
	}
	free(threads);
	
	return 0;
}