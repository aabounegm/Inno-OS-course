#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int append = 0;
	
	if(argc > 1 && strcmp(argv[1], "-a") == 0)
		append = 1;
	
	int file_count = argc - append - 1;
	FILE **files = malloc(file_count * sizeof(FILE*));
	if(files == NULL)
	{
		printf("An error occurred allocating memory\n");
		return 1;
	}
	const char *mode = append ? "a" : "w";
	for(int i=0; i<file_count; i++)
	{
		files[i] = fopen(argv[i+append+1], mode);
		if(files[i] == NULL)
		{
			printf("Error occurred opening file %s\n", argv[i+append+1]);
			return 2;
		}
	}
	
	char buffer[128];
	while(fgets(buffer, 127, stdin) != NULL)
	{
		printf("%s", buffer);
		for(int i=0; i<file_count; i++)
		{
			fprintf(files[i], "%s", buffer);
		}
	}
	
	for(int i=0; i<file_count; i++)
	{
		fclose(files[i]);
	}
	
	free(files);
	
	return 0;
}