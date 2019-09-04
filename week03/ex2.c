#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int n)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n-1; j++)
			if(arr[j+1] < arr[j])
				swap(arr+j+1, arr+j);
}

#define SIZE 9

int main()
{
	int x[SIZE] = {4,8,2,7,5,4,8,3,2};
	bubble_sort(x, SIZE);
	for(int i=0; i<SIZE; i++)
		printf("%d ", x[i]);
	printf("\n");
	return 0;
}