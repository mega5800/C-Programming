#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Triple
{
	int index1;
	int index2;
	int index_sum;
}Triple;

typedef struct Triple_Node
{
	Triple data;
	struct Triple_Node* Next;
}Triple_Node;

int** createMatrix(int* row, int*col);
int createArrayAndList(int**a, int row, int col, Triple** triple_arr, Triple_Node** triple_list);
Triple createThree(int a, int b, int c);
Triple* createThreeArr(Triple_Node* triple_list, int length_arr);
Triple_Node* createThreeList(int**a, int row, int col, int* length_arr);
int GetRandomNumber(int low, int high);
void PrintMatrix(int** a, int row, int col);
void PrintList(Triple_Node* list);
void PrintArray(Triple* arr, int length);
void PrintThree(Triple t, int type);
void FreeMatrix(int** a, int row);
void FreeList(Triple_Node* list);

void main()
{
	int row, col, length, **new_mat = NULL;
	srand((unsigned int)time(0));

	Triple_Node* triple_list = NULL;
	Triple* triple_arr = NULL;

	new_mat = createMatrix(&row, &col);

	PrintMatrix(new_mat, row, col);

	length = createArrayAndList(new_mat, row, col, &triple_arr, &triple_list);

	PrintList(triple_list);
	PrintArray(triple_arr, length);

	free(triple_arr);
	FreeList(triple_list);
	FreeMatrix(new_mat, row);
	system("PAUSE");
}

int createArrayAndList(int**a, int row, int col, Triple** triple_arr, Triple_Node** triple_list)
{
	int length_arr = 0;
	*triple_list = createThreeList(a, row, col, &length_arr);
	*triple_arr = createThreeArr(*triple_list, length_arr);
	return length_arr;
}
int** createMatrix(int* row, int* col)
{
	int**new_mat = NULL, i, n;

	printf("Enter numbers of rows:");
	scanf("%d", row);
	printf("Enter numbers of columns:");
	scanf("%d", col);

	new_mat = (int**)malloc((*row) * sizeof(int*));

	for (i = 0; i < (*row); i++)
	{
		new_mat[i] = (int*)malloc((*col) * sizeof(int));
		for (n = 0; n < (*col); n++)
			new_mat[i][n] = GetRandomNumber(1, 10);
	}

	return new_mat;
}

Triple_Node* createThreeList(int**a, int row, int col, int* length_arr)
{
	int i, n, first_node = 0;
	Triple_Node* head_list = NULL, *current_list = NULL;

	for (i = 0; i < row; i++)
	{
		for (n = 0; n < col; n++)
		{
			if (i + n == a[i][n])
			{
				if (first_node == 0)
				{
					head_list = (Triple_Node*)malloc(sizeof(Triple_Node));
					current_list = head_list;
					head_list->data = createThree(i, n, a[i][n]);
					first_node = 1;
					(*length_arr)++;
				}
				else
				{
					current_list->Next = (Triple_Node*)malloc(sizeof(Triple_Node));
					current_list = current_list->Next;
					current_list->data = createThree(i, n, a[i][n]);
					(*length_arr)++;
				}
			}
		}
	}
	current_list->Next = NULL;

	return head_list;
}
Triple* createThreeArr(Triple_Node* triple_list, int length_arr)
{
	int i;
	Triple* triple_arr = (Triple*)malloc(length_arr * sizeof(Triple));

	for (i = 0; i < length_arr; i++)
	{
		triple_arr[i] = triple_list->data;
		triple_list = triple_list->Next;
	}

	return triple_arr;
}
Triple createThree(int a, int b, int c)
{
	Triple new_trio;

	new_trio.index1 = a;
	new_trio.index2 = b;
	new_trio.index_sum = c;

	return new_trio;
}

int GetRandomNumber(int low, int high)
{
	int res = rand() % ((high + 1) - low) + low;
	return res;
}

void PrintMatrix(int** a, int row, int col)
{
	if (!a)
		printf("The matrix is empty\n");
	else
	{
		printf("\nMatrix result:\n");
		for (int i = 0; i < row; i++)
		{
			for (int n = 0; n < col; n++)
				printf("%d\t|", a[i][n]);
			printf("\n");
		}
		printf("\n");
	}
}
void PrintList(Triple_Node* list)
{
	if (!list)
		printf("\nThe list is empty\n");
	else
	{
		Triple_Node* print_node = list;

		printf("\nList result:\n");
		while (print_node != NULL)
		{
			PrintThree(print_node->data, 1);
			print_node = print_node->Next;
		}
		printf("\n");
	}
}
void PrintThree(Triple t, int type)
{
	printf("(%d , %d , %d) ", t.index1, t.index2, t.index_sum);
	if (type == 1)
		printf("-> ");
}
void PrintArray(Triple* arr, int length)
{
	int i;

	printf("\nArray result:\n");
	for (i = 0; i < length; i++)
	{
		printf("arr[%d] = ", i);
		PrintThree(arr[i], 0);
		printf("\n");
	}
	printf("\n");
}

void FreeList(Triple_Node* list)
{
	Triple_Node* to_free = list;

	while (to_free != NULL)
	{
		list = list->Next;
		free(to_free);
		to_free = list;
	}
}
void FreeMatrix(int** a, int row)
{
	for (int i = 0; i < row; i++)
		free(a[i]);
	free(a);
}