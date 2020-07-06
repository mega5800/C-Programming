#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

unsigned int* powerArray(int n);
void printArray(unsigned int* ptr, int n);

void main()
{
	int n;

	printf("Enter the length:");
	scanf("%d", &n);

	unsigned int* ptr = powerArray(n);
	printArray(ptr, n);

	free(ptr);
	system("PAUSE");
}

unsigned int* powerArray(int n)
{
	int i;
	unsigned int mult = 1;
	unsigned int* ptr = (unsigned int*)malloc(n * sizeof(unsigned int));

	if (!ptr)
		return NULL;

	for (i = 0; i < n; i++)
	{
		if (i % 32 == 0)
			mult = 1;

		ptr[i] = i % 32 == 0 ? 1 : mult;
		mult *= 2;
	}

	return ptr;
}

void printArray(unsigned int* ptr, int n)
{
	if (!ptr)
		printf("\nThe array is empty\n");
	else
	{
		int i;

		printf("\n");
		for (i = 0; i < n; i++)
			printf("array[%d] = %u\n", i, ptr[i]);
		printf("\n");
	}
}