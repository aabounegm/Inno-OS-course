#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	
	printf("Sizes:\n");
	printf("\tint: %lu\tfloat: %lu\tdouble: %lu\n", sizeof(a), sizeof(b), sizeof(c));

	printf("Values:\n");
	printf("\tint: %d\tfloat: %f\tdouble: %f\n", a, b, c);
	
	return 0;
}