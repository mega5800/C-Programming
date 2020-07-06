#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* input_array_dyn(int n, int type);
int All_Num_Check(int*arr, int n);
int Arr_Check(int*arr, int n);
void Ex5(void);

void main()
{
	Ex5();

	system("PAUSE");
}

void Ex5(void)
{
	int length;

	printf("Enter array's length:");
	scanf("%d", &length);

	int*arr = input_array_dyn(length, 0);

	if (All_Num_Check(arr, length) == 1)
		printf("The array has all the numbers\n");
	else
		printf("The array does not have all the numbers\n");

	free(arr);
}

int* input_array_dyn(int n, int type)
{
	int*arr;

	if (type == 0)
	{
		int i;
		arr = (int*)malloc(n * sizeof(int));

		printf("\nEnter array's values:\n");
		for (i = 0; i < n; i++)
		{
			printf("arr[%d] = ", i);
			scanf("%d", &arr[i]);
		}
		printf("\n");
	}
	else
		arr = (int*)calloc(n, sizeof(int));

	return arr;
}

int All_Num_Check(int*arr, int n)
{
	int i;

	int*help_arr = input_array_dyn(n, 1);

	for (i = 0; i < n; i++)
		++help_arr[arr[i]];

	return Arr_Check(help_arr, n);
}

int Arr_Check(int*arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
		if (arr[i] != 1)
		{
			free(arr);
			return 0;
		}

	free(arr);
	return 1;
}