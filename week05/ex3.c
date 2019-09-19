#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct {
	int count;
	int capacity;
	int *cookies;
} jar;

void* producer(void *vararg)
{
	while(1)
	{
		// jar full. wait
		while(jar.count >= jar.capacity);
		
		// if race condition happens, stop everything
		if(jar.count >= jar.capacity)
		{
			printf("FATAL ERROR! Trying to produce to a full buffer");
			exit(1);
		}

		// insert cookie
		jar.cookies[jar.count] = jar.count;	// rand();
		jar.count++;
	}
}
void* consumer(void *vararg)
{
	while(1)
	{
		// jar empty, wait
		while(jar.count <= 0);
		
		// if race condition happens, stop everything
		if(jar.count <= 0)
		{
			printf("FATAL ERROR! Trying to consume from an empty buffer");
			exit(1);
		}

		// consume cookie
		jar.cookies[jar.count] = 0;
		jar.count--;
	}
}

int main()
{
	jar.capacity = 5;
	jar.count = 0;
	jar.cookies = (int*) malloc(jar.capacity * sizeof(int));
	
	pthread_t prod, cons;
	
	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);
	
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);
	
	return 0;
}