#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void decode(char* string);

void main()
{
	char string[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt\0";

	printf("Before update:\n");
	printf("%s\n", string);

	decode(string);

	printf("\nAfter update:\n");
	printf("%s\n", string);

	system("pause");
}

void decode(char* string)
{
	int i = 0, count = 1;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] != ' ')
		{
			string[i] -= count;
			count++;
		}
		else
			count = 1;
	}
}