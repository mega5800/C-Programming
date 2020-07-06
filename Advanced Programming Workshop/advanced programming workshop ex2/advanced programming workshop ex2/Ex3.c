#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define Size 101

void createFile(char* filename);
char commonestLetter(char* filename);

void main()
{
	char c = 'a';
	createFile("input.txt");

	if ((c = commonestLetter("input.txt")) == '\0')
		printf("\nThe most common letter was not found\n");
	else
		printf("\nThe most common letter is:%c\n", c);

	system("pause");
}

void createFile(char* filename)
{
	FILE* my_file;
	char* my_string = (char*)malloc(Size * sizeof(char));

	my_file = fopen(filename, "w");

	if (my_file == NULL)
		exit(1);

	printf("Enter a string:");
	gets_s(my_string, Size - 1);
	
	fputs(my_string, my_file);

	free(my_string);
	fclose(my_file);
}
char commonestLetter(char* filename)
{
	FILE* my_file;
	int *letter_count = (int*)calloc(26, sizeof(int));
	int i, max = 0, result = -1, letter_flag = 0;
	char c = 'a';

	my_file = fopen(filename, "r");

	if (my_file == NULL)
		exit(1);

	while ((c = fgetc(my_file)) != EOF)
	{
		c -= ((c >= 97) && (c <= 122)) ? 32 : 0;
		if ((c >= 65) && (c <= 90))
		{
			letter_count[c - 65]++;
			letter_flag = 1;
		}
	}

	if (letter_flag == 1)
		for (i = 0; i < 26; i++)
			if (letter_count[i] >= max)
			{
				max = letter_count[i];
				result = i;
			}

	free(letter_count);
	fclose(my_file);

	return letter_flag == 0 ? '\0' : 65 + result;
}