#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB (1024*1024)

int main()
{
	int *data = NULL;
	size_t size = 0;
	for(int i=0; i<10; i++)
	{
		size += 10*MB;
		data = realloc(data, size);
		if(data == NULL)
		{
			printf("Error occured!\n");
			exit(1);
		}
		memset(data, 0, size);
		// printf("Have %ld MB of memory!\n", size / (1024*1024));
		sleep(1);
	}
	
	free(data);
	
	return 0;
}