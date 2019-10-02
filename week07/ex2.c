#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int N=0;
	
	if(argc == 2)
		N = strtol(argv[1], NULL, 10);

	while(N <= 0)
	{
		printf("Please enter a positive number: ");
		scanf("%d", &N);
	}
	
	int *arr = (int*)malloc(N * sizeof(int));
	
	if(arr == NULL)
	{
		printf("An error occured allocating memory!\n");
		return 1;
	}
	
	for(int i=0; i<N; i++)
		arr[i] = i;
	
	printf("Array contents:\n");
	printf("{ ");
	for(int i=0; i<N-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[N-1]);
	
	free(arr);
	
	return 0;
}