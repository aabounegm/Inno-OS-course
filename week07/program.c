#include <stdio.h>

char *msg = "Hello world!";

int uninitialized_global;

int main(int argc, char *argv[])
{
	const double PI = 3.14;
	int random_number;
	
	printf("Got %d args!\n", argc);
	printf("%s\n", msg);
	
	return 0;
}