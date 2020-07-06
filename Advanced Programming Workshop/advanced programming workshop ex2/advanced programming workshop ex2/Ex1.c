#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define Size 101

char** split(char* string, char letter, int* size);
int letterCount(char* string, char letter);
void PrintResult(char** mat_str, int mat_size, char letter);
void Free_Mat_Str(char** mat_str, int mat_size);

void main()
{
	int size_string_arr = 0;
	char letter, *string = (char*)malloc(Size * sizeof(char)), **mat_string = NULL;

	printf("Enter a string:");
	gets_s(string, Size - 1);

	printf("Enter a letter:");
	scanf("%c", &letter);

	mat_string = split(string, letter, &size_string_arr);

	PrintResult(mat_string, size_string_arr, letter);

	Free_Mat_Str(mat_string, size_string_arr);
	free(string);

	system("pause");
}

void PrintResult(char** mat_str, int mat_size, char letter)
{
	int i;
	printf("\nThe size is:%d\n", mat_size);

	if (mat_str != NULL)
	{
		printf("\nThe new strings are:\n");

		for (i = 0; i < mat_size; i++)
			printf("String[%d] = %s\n", i, mat_str[i]);
	}
	else
		printf("Strings who starts with the letter \"%c\" were not found\n", letter);
}

void Free_Mat_Str(char** mat_str, int mat_size)
{
	int i;

	if (mat_str != NULL)
	{
		for (i = 0; i < mat_size; i++)
			free(mat_str[i]);

		free(mat_str);
	}
}

char** split(char* string, char letter, int* size)
{
	int i, n = 0, string_count = 0;
	char**mat_str = NULL, a = '\0';

	*size = letterCount(string, letter);

	if (*size == 0)
		return NULL;

	mat_str = (char**)malloc(*size * sizeof(char*));
	if ((string[0] == letter) || (string[0] + 32 == letter))
	{
		mat_str[string_count] = (char*)malloc(Size * sizeof(char));

		while ((string[n] != ' ') && (string[n] != '\0'))
		{
			mat_str[string_count][n] = string[n];
			n++;
		}
		mat_str[string_count][n] = '\0';
		string_count++;
	}

	n = n == 0 ? 1 : n;

	for (i = n; (a = string[i]) != '\0'; i++)
	{
		if (string[i - 1] == ' ')
			if ((string[i] == letter) || (string[i] + 32 == letter))
			{
				n = 0;
				mat_str[string_count] = (char*)malloc(Size * sizeof(char));

				while ((string[i + n] != ' ') && (string[i + n] != '\0'))
				{
					mat_str[string_count][n] = string[i + n];
					n++;
				}
				mat_str[string_count][n] = '\0';

				string_count++;
				i += n - 1;
			}
	}

	return mat_str;
}
int letterCount(char* string, char letter)
{
	int count = 0, i;
	char a = '\0';
	if ((string[0] == letter) || (string[0] + 32 == letter))
		count++;

	for (i = 1; (a = string[i]) != '\0'; i++)
	{
		a += ((a >= 65) && (a <= 90)) ? 32 : 0;
		if ((letter == a) && (string[i - 1] == ' '))
			count++;
	}

	return count;
}