#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_A 8
#define COL_A 9
#define ROW_B 9
#define COL_B 10

typedef int Matrix_A[ROW_A][COL_A];
typedef int Matrix_B[ROW_B][COL_B];

void Fill_Matrix_A(Matrix_A mat_a);
void Fill_Matrix_B(Matrix_B mat_b);
int** matrixMultiplication(Matrix_A a, Matrix_B b);
void PrintMatrix(int** a);
void Print_a(Matrix_A a);
void Print_b(Matrix_B b);
void FreeMatrix(int** a);
int GetRandomNumber(int low, int high);

void main()
{
	int** new_mat = NULL;
	Matrix_A a = { 0 };
	Matrix_B b = { 0 };
	srand((unsigned int)time(0));

	if (COL_A == ROW_B)
	{
		Fill_Matrix_A(a);
		Fill_Matrix_B(b);

		Print_a(a);
		Print_b(b);

		new_mat = matrixMultiplication(a, b);
		PrintMatrix(new_mat);

		FreeMatrix(new_mat);
	}
	else
		printf("The matrices have different sizes.\nMultiplication can't be done\n");

	system("PAUSE");
}

void Fill_Matrix_A(Matrix_A mat_a)
{
	int i, n;

	for (i = 0; i < ROW_A; i++)
		for (n = 0; n < COL_A; n++)
			mat_a[i][n] = GetRandomNumber(-20, 20);
}
void Fill_Matrix_B(Matrix_B mat_b)
{
	int i, n;

	for (i = 0; i < ROW_B; i++)
		for (n = 0; n < COL_B; n++)
			mat_b[i][n] = GetRandomNumber(-20, 20);
}

int** matrixMultiplication(Matrix_A a, Matrix_B b)
{
	int i, j, k, **New_Mat = NULL;

	New_Mat = (int**)malloc(ROW_A * sizeof(int*));

	for (i = 0; i < ROW_A; i++)
	{
		New_Mat[i] = (int*)calloc(COL_B, sizeof(int));

		for (j = 0; j < COL_B; j++)
			for (k = 0; k < COL_A; k++)
				New_Mat[i][j] += a[i][k] * b[k][j];
	}

	return New_Mat;
}

int GetRandomNumber(int low, int high)
{
	int res = rand() % ((high + 1) - low) + low;
	return res;
}

void PrintMatrix(int** a)
{
	if (!a)
		printf("The matrix is empty\n");
	else
	{
		printf("Result:\n");
		for (int i = 0; i < ROW_A; i++)
		{
			for (int n = 0; n < COL_B; n++)
				printf("%d\t|", a[i][n]);
			printf("\n");
		}
		printf("\n");
	}
}
void Print_a(Matrix_A a)
{
	printf("Matrix a:\n");
	for (int i = 0; i < ROW_A; i++)
	{
		for (int n = 0; n < COL_A; n++)
			printf("%d\t|", a[i][n]);
		printf("\n");
	}
	printf("\n");
}
void Print_b(Matrix_B b)
{
	printf("Matrix b:\n");
	for (int i = 0; i < ROW_B; i++)
	{
		for (int n = 0; n < COL_B; n++)
			printf("%d\t|", b[i][n]);
		printf("\n");
	}
	printf("\n");
}

void FreeMatrix(int** a)
{
	for (int i = 0; i < ROW_A; i++)
		free(a[i]);
	free(a);
}