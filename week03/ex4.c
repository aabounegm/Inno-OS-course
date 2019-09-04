// QuickSort algorithm with adaptation from GeeksForGeeks
#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j=low; j <= high-1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr+i, arr+j);
        }
    }
    swap(arr+i+1, arr+high);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
		return;
	int p = partition(arr, low, high);
	quickSort(arr, low, p - 1);
	quickSort(arr, p + 1, high);
}

void printArray(int arr[], int size)
{
	printf("{ ");
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("}\n");
}

#define SIZE 7

int main()
{
    int arr[SIZE] = {10, 7, 8, 9, 1, 5, 3};
	printf("Original array:\n\t");
    printArray(arr, SIZE);
	
    quickSort(arr, 0, SIZE-1);
	
    printf("Sorted array:\n\t");
    printArray(arr, SIZE);
    return 0;
}