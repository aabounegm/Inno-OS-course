#include <stdio.h>

int main()
{
	FILE *rand = fopen("/dev/random", "r");
	if(rand == NULL)
	{
		printf("Error opening /dev/random\n");
		return 1;
	}
	char buffer[21];
	int i=0;
	while(i<20)
	{
		int c = fgetc(rand);
		if(c == EOF)
		{
			printf("Error while reading\n");
			return 2;
		}
		if(c <= 31 || c>=127)
			continue;
		buffer[i] = c;
		i++;
	}
	buffer[20] = '\0';
	for(int i=0; i<20; i++)
		printf("%c", buffer[i]);
	printf("\n");
	fclose(rand);
	return 0;
}