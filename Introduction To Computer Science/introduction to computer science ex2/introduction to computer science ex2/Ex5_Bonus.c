#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* input_array_dyn(int n);
int All_Num_Check(int*arr, int n);
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

	int*arr = input_array_dyn(length);

	if (All_Num_Check(arr, length) == 1)
		printf("The array has all the numbers\n");
	else
		printf("The array does not have all the numbers\n");

	free(arr);
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
	printf("\n");

	return arr;
}

int All_Num_Check(int*arr, int n)
{
	int i, temp;

	for (i = 0; i < n; i++)
		if (i == 0)
			temp = arr[i] ^ i;
		else
			temp = temp ^ (i ^ arr[i]);

	return temp == 0 ? 1 : 0;
}