#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Ex4_B(void);
int* input_array_dyn(int n, int type);
int Permutation_Check(int*a, int*b, int n);

void main()
{
	Ex4_B();

	system("PAUSE");
}

void Ex4_B()
{
	int length;

	printf("Enter array's length:");
	scanf("%d", &length);

	printf("\nEnter the values for the first array:\n");
	int*arr_A = input_array_dyn(length, 0);

	printf("\nEnter the values for the second array:\n");
	int*arr_B = input_array_dyn(length, 0);

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
	int*help_arr = input_array_dyn(n, 1);

	for (i = 0; i < n; i++)
	{
		++help_arr[a[i]];
		--help_arr[b[i]];
	}

	for (i = 0; i < n; i++)
		if (help_arr[i] != 0)
		{
			free(help_arr);
			return 0;
		}

	free(help_arr);
	return 1;
}

int* input_array_dyn(int n, int type)
{
	int*arr;

	if (type == 0)
	{
		int i, temp;
		arr = (int*)malloc(n * sizeof(int));

		for (i = 0; i < n; i++)
		{
			printf("arr[%d] = ", i);
			scanf("%d", &temp);
			arr[i] = temp - 1;
		}
	}
	else
		arr = (int*)calloc(n, sizeof(int));

	return arr;
}