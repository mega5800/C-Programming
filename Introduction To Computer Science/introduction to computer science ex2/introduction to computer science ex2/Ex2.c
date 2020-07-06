#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Ex2(void);
int* input_array_dyn(int n);
int Get_Num_Sum(int*arr, int n);
void Swap(int *a, int *b);
void Print(int *arr, int length);
void Clear_Screen(void);

void main()
{
	Ex2();

	system("PAUSE");
}

void Ex2()
{
	int length;

	printf("Enter array's length:");
	scanf("%d", &length);

	int*arr = input_array_dyn(length);

	Clear_Screen();

	printf("This array has %d numbers\n", Get_Num_Sum(arr, length));

	Print(arr, length);

	free(arr);
}

int Get_Num_Sum(int*arr, int n)
{
	int num_count = 0, index_1 = 0, index_2 = 1;

	while ((index_1 < n) && (index_2 < n))
	{
		if ((arr[index_1] != 0) && (arr[index_2] == 0))
		{
			++num_count;
			++index_1;
			++index_2;
		}

		if ((arr[index_1] == 0) && (arr[index_2] != 0))
			while ((arr[index_1] == 0) && (arr[index_2] != 0) && (index_1 < n - 1) && (index_2 < n))
			{
				Swap(arr + index_1, arr + index_2);
				num_count++;
				++index_1;
				++index_2;
			}

		while ((arr[index_1] == 0) && (arr[index_2] == 0) && (index_1 < n - 1) && (index_2 < n))
			++index_2;
	}

	return num_count;
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* input_array_dyn(int n)
{
	int i;
	int*arr = (int*)malloc(n * sizeof(int));

	printf("\nEnter array's values:\n");
	for (i = 0; i < n; i++)
	{
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	return arr;
}

void Print(int *arr, int length)
{
	int i;
	printf("\nThe array looks like this:\n");
	for (i = 0; i < length; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	printf("\n");
}

void Clear_Screen()
{
	system("@cls||clear");
}