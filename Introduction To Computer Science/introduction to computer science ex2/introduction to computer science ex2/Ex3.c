#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Ex3(void);
void Clear_Screen(void);
int* input_array_dyn(int n);
int* Get_Mutual_Array(int*arr_a, int*arr_b, int length_a, int length_b, int*length_c);
void Swap(int* a, int* b);
void Print(int*arr, int n);
int Partition(int *arr, int left, int right);
void QuickSort(int*arr, int first, int last);

void main()
{
	Ex3();

	system("PAUSE");
}

void Ex3()
{
	int length_a, length_b, length_c = 0;

	printf("Enter the first  array's length:");
	scanf("%d", &length_a);

	printf("\nEnter the values for the first array:\n");
	int*arr_A = input_array_dyn(length_a);

	Clear_Screen();

	printf("Enter the second array's length:");
	scanf("%d", &length_b);

	printf("\nEnter the values for the second array:\n");
	int*arr_B = input_array_dyn(length_b);

	Clear_Screen();

	int*arr_C = Get_Mutual_Array(arr_A, arr_B, length_a, length_b, &length_c);
	Print(arr_C, length_c);

	free(arr_A);
	free(arr_B);
	free(arr_C);
}

int* Get_Mutual_Array(int*arr_a, int*arr_b, int length_a, int length_b, int* length_c)
{
	int i = 0, n = 0, count_c = 0;
	int*arr_c = length_a > length_b ? (int*)malloc(length_b * sizeof(int)) : (int*)malloc(length_a * sizeof(int));

	QuickSort(arr_a, 0, length_a - 1);
	QuickSort(arr_b, 0, length_b - 1);

	while ((i < length_a) && (n < length_b))
	{
		while ((arr_a[i] == arr_b[n]) && (i < length_a) && (n < length_b))
		{
			arr_c[count_c++] = arr_a[i++];
			n++;
			*length_c += 1;
		}
		while ((arr_a[i] < arr_b[n]) && (i < length_a))
			i++;
		while ((arr_a[i] > arr_b[n]) && (n < length_b))
			n++;
	}

	arr_c = realloc(arr_c, *length_c * sizeof(int));
	return arr_c;
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

void Print(int*arr, int n)
{
	int i;

	printf("The new array's values are:\n");
	for (i = 0; i < n; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
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

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void Clear_Screen()
{
	system("@cls||clear");
}