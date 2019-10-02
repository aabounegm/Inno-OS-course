#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **s = (char**)malloc(sizeof(char*));	// allocate memory for the pointer
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %p\n", s);	 // would be meaningless to print *s, as it is the same thing as s[0] (next)
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	
	free(s);
	return 0;
}
