#include <stdio.h>
#include <unistd.h>

#define MSG_SIZE 50

int main()
{
	char str1[MSG_SIZE] = "Hello world!";
	char str2[MSG_SIZE] = "";
	printf("Contents of str1: '%s'\n", str1);
	printf("Contents of str2: '%s'\n", str2);
	printf("Piping...\n");
	
	int files[2];
	
	if(pipe(files) < 0)
		return 1;
	
	write(files[1], str1, MSG_SIZE);
	
	read(files[0], str2, MSG_SIZE);
	
	printf("After piping:\n");
	printf("Contents of str1: '%s'\n", str1);
	printf("Contents of str2: '%s'\n", str2);
	
	return 0;
}