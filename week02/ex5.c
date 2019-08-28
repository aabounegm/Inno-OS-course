#include <stdio.h>
#include <string.h>

void regular(int n)
{
	for(int row=1; row<=n; row++)
	{
		for(int spaces=0; spaces<n-row; spaces++)
			printf(" ");
		for(int column=1; column<=2*row-1; column++)
			printf("*");
		printf("\n");
	}
}
void right(int n)
{
	for(int row=1; row<=n; row++)
	{
		for(int column=1; column<=row; column++)
			printf("*");
		printf("\n");
	}
}
void obtuse(int n)
{
	right(n);
	for(int row=1; row<=n; row++)
	{
		for(int column=n; column>row; column--)
			printf("*");
		printf("\n");
	}
}

void square(int n)
{
	for(int row=1; row<=n; row++)
	{
		for(int column=1; column<=n; column++)
			printf("*");
		printf("\n");
	}
}


int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: %s <number of lines> [right|obtuse|square]\n", argv[0]);
		return 1;
	}
	int n;
	int scanned = sscanf(argv[1], "%d", &n);
	if(scanned != 1)
	{
		printf("Usage: %s <number of lines> [right|obtuse|square]\n", argv[0]);
		return 1;
	}
	int to_print = 0;
	if(argc == 3)
	{
		char *option = argv[2];
		if(strcmp(option, "right") == 0)
			to_print = 1;
		else if(strcmp(option, "obtuse") == 0)
			to_print = 2;
		else if(strcmp(option, "square") == 0)
			to_print = 3;
		else
			to_print = -1;
	}
	
	switch(to_print)
	{
		case -1:
			printf("Invalid option\n");
			return 2;
		case 0: regular(n); break;
		case 1: right(n); break;
		case 2: obtuse(n); break;
		case 3: square(n); break;
		default:
			printf("An unknown error occured!\n");
			return 3;
	}
	
	return 0;
}