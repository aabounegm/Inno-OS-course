#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define MB (1024*1024)

int main()
{
	int *data = NULL;
	size_t size = 0;
	struct rusage usage;
	char *div = "----------------------------------------------------------"
				"---------------------------------------------------------";
	printf("%s\n", div);
	printf("| User CPU time (usec) | System CPU time (usec) | Page faults"
		   " (w/o I/O) | Page faults (w/ I/O) | Context switches |\n");
	printf("%s\n", div);
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
		
		getrusage(RUSAGE_SELF, &usage);
		printf("| %20ld | %22ld | %21ld | %20ld | %16ld |\n",
			usage.ru_utime.tv_usec,
			usage.ru_stime.tv_usec,
			usage.ru_minflt,
			usage.ru_majflt,
			usage.ru_nvcsw + usage.ru_nivcsw
		);
		
		// printf("Have %ld MB of memory!\n", size / (1024*1024));
		sleep(1);
	}
	printf("%s\n", div);
	free(data);
	
	return 0;
}