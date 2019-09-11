#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	/**
	  * The number in N determines the depth of the fork tree
	  * Each process gets forked into 2, each of which get forked into 2 more
	  * The total number of processes will reach 2^N
	  */
	int N = 3;
	if(argc == 2)
		N = strtol(argv[1], NULL, 10);

	for(int i=0; i<N; i++)
	{
		fork();
		sleep(5);
	}
	return 0;
}