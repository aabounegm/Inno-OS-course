#include <stdio.h>
#include <stdlib.h>
#include <string.h>			// for memcpy()

#define min(a, b) ( ((a) < (b)) ? (a) : (b) )

/**
  * The extra parameter (old_size) does not exist in the standard realloc,
  *  but the standard realloc uses platform-dependent functionality.
  * This parameter was introduced to make the function as general and platform-independent as possible
  */
void* my_realloc(void *ptr, size_t new_size, size_t old_size)
{
	// size = 0 means calling free()
	if(new_size == 0)
	{
		free(ptr);
		return NULL;
	}
	
	// given NULL, means same behavior as malloc()
	if(ptr == NULL)
		return malloc(new_size);
	
	void *new_ptr = malloc(new_size);
	if(new_ptr == NULL)
		return NULL;
	
	// copy the data
	size_t min_size = min(old_size, new_size);
	memcpy(new_ptr, ptr, min_size);

	// free initial pointer
	free(ptr);
	
	return new_ptr;
}

void print_array(int *arr, int size)
{
	if(arr == NULL)
		return;
	printf("{ ");
	int i=0;
	for(i=0; i<size-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[i]);
}

int main()
{
	int size = 5, old_size;
	printf("Allocating space for %d ints...\n", size);
	int *arr = (int*)my_realloc(NULL, size*sizeof(int), 0);
	for(int i=0; i<size; i++)
		arr[i] = i;
	printf("Array content:\n ");
	print_array(arr, size);
	
	// Increase size
	old_size = size;
	size = 10;
	printf("\nResizing to be %d ints long (without initialization)...\n", size);
	arr = (int*)my_realloc(arr, size*sizeof(int), old_size*sizeof(int));
	printf("New array contents:\n ");
	print_array(arr, size);

	// Decrease size
	old_size = size;
	size = 2;
	printf("\nResizing to be %d ints long (without initialization)...\n", size);
	arr = (int*)my_realloc(arr, size*sizeof(int), old_size*sizeof(int));
	printf("New array contents:\n ");
	print_array(arr, size);
	
	// Free the array
	printf("\nFreeing the array...\n");
	arr = (int*)my_realloc(arr, 0, 0);
	printf("Pointer after freeing: %p\n", arr);
	
	return 0;
}