#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define Size 101
char* clearDigitsAndSpaces(char* string);

void main()
{
	char* string = (char*)malloc(Size * sizeof(char));

	printf("Enter a string:");
	gets_s(string, Size - 1);

	printf("\nBefore update:\n");
	printf("%s\n", string);

	string = clearDigitsAndSpaces(string);

	printf("\nAfter update:\n");
	printf("%s\n", string);

	free(string);
	system("pause");
}

char* clearDigitsAndSpaces(char * string)
{
	int i, j = 0;
	char* new_string = malloc(Size);

	for (i = 0; string[i] != '\0'; i++)
		if (!((string[i] == ' ') || ((string[i] >= 48) && (string[i] <= 57))))
		{
			new_string[j] = string[i];
			j++;
		}
	new_string[j] = '\0';

	return new_string;
}