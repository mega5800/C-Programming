#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Ex4_A(void);
int* input_array_dyn(int n);
int Permutation_Check(int*a, int*b, int n);
void Swap(int* a, int* b);
int Partition(int *arr, int left, int right);
void QuickSort(int*arr, int first, int last);

void main()
{
	Ex4_A();

	system("PAUSE");
}

void Ex4_A()
{
	int length;

	printf("Enter array's length:");
	scanf("%d", &length);

	printf("\nEnter the values for the first array:\n");
	int*arr_A = input_array_dyn(length);

	printf("\nEnter the values for the second array:\n");
	int*arr_B = input_array_dyn(length);

	if (Permutation_Check(arr_A, arr_B, length) == 1)
		printf("\nThe arrays are valid permutations of each other\n");
	else
		printf("\nThe arrays are invalid permutations of each other\n");

	free(arr_A);
	free(arr_B);
}

int Permutation_Check(int*a, int*b, int n)
{
	int i;

	QuickSort(a, 0, n - 1);
	QuickSort(b, 0, n - 1);

	for (i = 0; i < n; i++)
		if (a[i] != b[i])
			return 0;

	return 1;
}

int* input_array_dyn(int n)
{
	int i;
	int*arr = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	return arr;
}

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Partition(int* arr, int left, int right)
{
	int first = left, pivot = arr[first], pos;

	while (left < right)
	{
		while (arr[right] > pivot)
			--right;
		while ((left < right) && (arr[left] <= pivot))
			++left;

		if (left < right)
			Swap(arr + left, arr + right);
	}

	pos = right;
	arr[first] = arr[pos];
	arr[pos] = pivot;

	return pos;
}

void QuickSort(int*arr, int first, int last)
{
	int pos;
	if (first < last)
	{
		pos = Partition(arr, first, last);
		QuickSort(arr, first, pos - 1);
		QuickSort(arr, pos + 1, last);
	}
}