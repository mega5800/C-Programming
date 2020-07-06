#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Size 101

void memoryReport(char* declaration, char* filename);
void Set_Name_To_String(char* string, char* sub_str, int* index, int* is_pointer, int* is_arr);
int Convert_String_To_Int(char* string, int arr_index, int* str_index);
void DeleteSpace(char* string);
int My_Size_Of(char* string, int *index);
int LongLongCheck(char* string);
int Count_Comma(char* string);
void Insert_Data_And_Print(char**str_mat, int size, char* filename);
void Free_Mat_Str(char** mat_str, int mat_size);

void main()
{
	char* declaration = (char*)malloc(Size * sizeof(char)), *filename = (char*)malloc(Size * sizeof(char));

	printf("Enter the declaration:\n");
	gets_s(declaration, Size - 1);

	printf("\nEnter the file name:\n");
	scanf(" %s", filename);

	memoryReport(declaration, filename);

	free(declaration);
	free(filename);
	system("pause");
}

void memoryReport(char* declaration, char* filename)
{
	int comma_count, for_i = 0, string_i = 0, my_size_of = 0, ptr_flag = 0, arr_index = 0, size_res;
	char** memory_mat = NULL, tmp_str[Size];

	DeleteSpace(declaration);
	my_size_of = My_Size_Of(declaration, &string_i);
	comma_count = Count_Comma(declaration);
	memory_mat = (char**)malloc(comma_count * sizeof(char*));

	for (for_i = 0; for_i < comma_count; for_i++)
	{
		memory_mat[for_i] = (char*)malloc(Size * sizeof(char));
		Set_Name_To_String(declaration, memory_mat[for_i], &string_i, &ptr_flag, &arr_index);
		if (arr_index != 0)
			size_res = my_size_of * Convert_String_To_Int(declaration, arr_index, &string_i);
		else
			size_res = ptr_flag == 1 ? 4 : my_size_of;
		
		sprintf(tmp_str, " requires %d bytes\n", size_res);
		strcat(memory_mat[for_i], tmp_str);
		DeleteSpace(memory_mat[for_i]);
		arr_index = ptr_flag = 0;
	}

	Insert_Data_And_Print(memory_mat, comma_count, filename);

	Free_Mat_Str(memory_mat, comma_count);
}
void Set_Name_To_String(char* string, char* sub_str, int* index, int* is_pointer, int* is_arr)
{
	int i = 0;

	while ((string[*index] != ',') && (string[*index] != ';') && (string[*index] != '['))
	{
		if (string[*index] != '*')
			sub_str[i++] = string[*index];
		else
			*is_pointer = 1;
		*index += 1;
	}

	*is_arr = (string[*index] == '[') ? (*index + 1) : 0;

	sub_str[i] = '\0';
	*index += 1;
}
int Convert_String_To_Int(char* string, int arr_index, int* str_index)
{
	int i = 0, res = 0;
	char num[Size];

	while (string[arr_index] != ']')
		num[i++] = string[arr_index++];
	num[i] = '\0';

	*str_index = string[arr_index + 1] == ' ' ? arr_index + 3 : arr_index + 2;

	sscanf(num, "%d", &res);

	return res;
}
void DeleteSpace(char* string)
{
	int i = 0, j = 0, space_count = 0;
	char tmp_string[Size];

	while (string[i] == ' ')
		i++;

	while (string[i] != '\0')
	{
		if (string[i] != ' ')
		{
			tmp_string[j++] = string[i];
			space_count = 0;
		}
		else
			if (space_count == 0)
			{
				tmp_string[j++] = string[i];
				space_count = 1;
			}
		i++;
	}

	tmp_string[j] = '\0';
	strcpy(string, tmp_string);
}

int Count_Comma(char* string)
{
	int i = 0, res = 1;

	while (string[i] != '\0')
		res += string[i++] == ',' ? 1 : 0;

	return res;
}

int My_Size_Of(char* string, int *index)
{
	int res = 0;

	switch (string[0])
	{
	case 'c':
		res = sizeof(char);
		*index = string[4] == ' ' ? 5 : 4;
		break;
	case 's':
		res = sizeof(short);
		*index = string[5] == ' ' ? 6 : 5;
		break;
	case 'i':
		res = sizeof(int);
		*index = string[4] == ' ' ? 4 : 3;
		break;
	case 'f':
		res = sizeof(float);
		*index = string[5] == ' ' ? 6 : 5;
		break;
	case 'd':
		res = sizeof(double);
		*index = string[6] == ' ' ? 7 : 6;
		break;
	case 'l':
		res = LongLongCheck(string) == 1 ? sizeof(long long) : sizeof(long);
		if (res == sizeof(long))
			*index = string[4] == ' ' ? 5 : 4;
		else
			*index = string[9] == ' ' ? 10 : 9;
		break;
	}

	return res;
}
int LongLongCheck(char* string)
{
	int i;
	char compare[10];

	for (i = 0; i < 9; i++)
		compare[i] = string[i];
	compare[i] = '\0';

	return !strcmp(compare, "long long");
}

void Insert_Data_And_Print(char**str_mat, int size, char* filename)
{
	int i;
	FILE *my_file = NULL;
	char str[Size];

	my_file = fopen(filename, "w");

	for (i = 0; i < size; i++)
		fputs(str_mat[i], my_file);

	fclose(my_file);

	i = 0;
	my_file = fopen(filename, "r");

	printf("\nThe memory report is:\n");
	while (fgets(str, Size - 1, my_file))
		printf("%s", str);

	fclose(my_file);
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