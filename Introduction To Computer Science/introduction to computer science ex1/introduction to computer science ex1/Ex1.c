#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Question 1
void Ex1(void);
int Sequence_Check(int);

void Ex1(void)
{
	int k;

	printf("Please enter the main number:");
	scanf("%d", &k);
	printf("\n");

	if (Sequence_Check(k))
		printf("\n%d is smaller then the sequence\n", k);
	else
		printf("\n%d is bigger then the sequence\n", k);
}
int Sequence_Check(int k)
{
	int loop_num = 0, max1 = 0, max2 = 0;

	while ((max1 + max2 < k) && (loop_num != -1))
	{
		printf("Please enter a number:");
		scanf("%d", &loop_num);

		if (max1 > max2)
			max2 = loop_num;
		else
			max1 = loop_num;
	}

	if (loop_num == -1)
		return 0;
	return 1;
}
//Question 1

//Question 2
void Ex2(void);
int Binary_Sequence_Check(int);

void Ex2(void)
{
	int n;

	printf("Please enter the length:");
	scanf("%d", &n);
	printf("\n");

	printf("\nthe longest Sequence is:%d\n", Binary_Sequence_Check(n));
}
int Binary_Sequence_Check(int num)
{
	if (num == 0)
		return 0;

	int i, last_num, loop_num, count = 1, max = 0;

	printf("Please enter a number:");
	scanf("%d", &loop_num);

	last_num = loop_num;

	for (i = 1; i < num; i++)
	{
		printf("Please enter a number:");
		scanf("%d", &loop_num);

		if (loop_num == last_num)
			++count;
		else
		{
			if (count > max)
				max = count;

			count = 1;
			last_num = loop_num;
		}
	}

	return max;
}
//Question 2

//Question 3
void Ex3(void);
void Get_Biggest_Solution_Distance(int);

void Ex3(void)
{
	int n;

	printf("Please enter the main number:");
	scanf("%d", &n);
	printf("\n");

	Get_Biggest_Solution_Distance(n);
}
void Get_Biggest_Solution_Distance(int n)
{
	int max_X = 0, max_Y = 0, distance = -1, x = 0, y;

	while (3 * x <= n)
	{
		y = n - 3 * x;

		if (y % 5 == 0)
		{
			y /= 5;
			if (x > y)
			{
				if (distance < x - y)
				{
					max_X = x;
					max_Y = y;
				}
			}
			else
				if (distance < y - x)
				{
					max_X = x;
					max_Y = y;
				}
		}

		++x;
	}

	printf("The solution with the biggest distance is: (%d , %d)\n", max_X, max_Y);
}
//Question 3

//Question 4
void Ex4(void);
double Calculate_E(int, int);

void Ex4(void)
{
	int n, x;

	printf("Please enter an integer:");
	scanf("%d", &n);
	printf("Please enter a real number:");
	scanf("%d", &x);
	printf("\n");

	printf("e^%d = %lf\n", x, Calculate_E(n, x));
}
double Calculate_E(int n, int x)
{
	int i;
	double sum_e = 1, fac = 1, pow = 1;

	for (i = 1; i <= n; i++)
	{
		sum_e += ((x*pow) / (fac));

		pow *= x;
		fac *= (i + 1);
	}

	return sum_e;
}
//Question 4

//Question 5
void Ex5(void);
int Is_Number_Big(int);
int Get_Dividers_Sum(int);

void Ex5(void)
{
	int n;

	printf("Please enter a number:");
	scanf("%d", &n);
	printf("\n");

	if (Is_Number_Big(n))
		printf("%d is a big number\n", n);
	else
		printf("%d is not a big number\n", n);
}
int Is_Number_Big(int n)
{
	int i, max_divide_num, divide_count = 1, divide_count_max = 0;

	for (i = 1; i <= n; i++)
	{
		divide_count = Get_Dividers_Sum(i);

		if (divide_count > divide_count_max)
		{
			divide_count_max = divide_count;
			max_divide_num = i;
		}
	}

	if (max_divide_num == n)
		return 1;
	return 0;
}
int Get_Dividers_Sum(int n)
{
	int count = 0, i;

	for (i = 1; i <= sqrt(n); i++)
		if (n%i == 0)
		{
			if (n / i == i)
				++count;
			else
				count += 2;
		}

	return count;
}
//Question 5

//Question 6
void Ex6(void);
int Remove_Digit(int, int);

void Ex6(void)
{
	int n, d;

	printf("Please enter a number:");
	scanf("%d", &n);
	printf("Please enter a digit:");
	scanf("%d", &d);
	printf("\n");

	printf("NEW NUM: %d\n", Remove_Digit(n, d));
}
int Remove_Digit(int n, int d)
{
	if (n / 10 == 0)
	{
		if (n % 10 == d)
			return 0;
		else
			return n % 10;
	}
	else
		if (n % 10 == d)
			return Remove_Digit(n / 10, d);

	return Remove_Digit(n / 10, d) * 10 + Remove_Digit(n % 10, d);
}
//Question 6

void main()
{
	Ex3();

	system("PAUSE");
}