#include <stdio.h>

void swap(int*, int*);

int main()
{
	int a, b;
	printf("Enter 2 numbers: ");
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("After swapping: %d %d\n", a, b);
	
	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}