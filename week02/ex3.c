#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	if(argc != 2 || sscanf(argv[1], "%d", &n) != 1)
	{
		printf("Usage: %s [number of lines]\n", argv[0]);
		return 1;
	}
	
	for(int row=1; row<=n; row++)
	{
		for(int spaces=0; spaces<n-row; spaces++)
			printf(" ");
		for(int column=1; column<=2*row-1; column++)
			printf("*");
		printf("\n");
	}
	return 0;
}