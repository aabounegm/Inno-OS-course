#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
	char buffer[MAX_LEN];
	printf("Enter a string (max %d characters): ", MAX_LEN);
	if(fgets(buffer, MAX_LEN, stdin) == NULL) 
	{
		printf("An error occured\n");
		return 1;
	}
	int len = strlen(buffer);
	for(int i=len-1; i>=0; i--)
	{
		putchar(buffer[i]);
	}
	putchar('\n');
	
	return 0;
}
