#include <stdio.h>
#include <unistd.h>

#define STR_LEN 6

int main()
{
	char text[STR_LEN+1] = "Hello\n";
	
	setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	for(int i=0; i<STR_LEN; i++)
	{
		printf("%c", text[i]);
		sleep(1);
	}
	return 0;
}