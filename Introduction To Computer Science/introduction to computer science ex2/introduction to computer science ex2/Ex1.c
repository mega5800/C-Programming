#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Ex1(void);
double* input_array_dyn(int n);
void Get_Best_Buy_Sale_Times(double*arr, int n, int*sale, int*buy);

void main()
{
	Ex1();

	system("PAUSE");
}

void Ex1()
{
	int length, buy, sale;

	printf("Enter array's length:");
	scanf("%d", &length);

	double*stock = input_array_dyn(length);

	Get_Best_Buy_Sale_Times(stock, length, &buy, &sale);
	printf("The best time to sale is: %d, at this time the stock price is: %.2lf\n", sale, stock[sale]);
	printf("The best time to buy  is: %d, at this time the stock price is: %.2lf\n", buy, stock[buy]);
	printf("The revenue is: %.2lf\n", stock[buy] > stock[sale] ? stock[buy] - stock[sale] : 0);

	free(stock);
}

void Get_Best_Buy_Sale_Times(double*arr, int n, int*sale, int*buy)
{
	int count = 1, index_buy = 0, index_sale = 1, better_Rev = 0;
	double max_rev = 0;

	while (count < n)
	{
		while ((arr[count] > arr[index_buy]) && (count < n))
		{
			if (arr[count] - arr[index_buy] > max_rev)
			{
				max_rev = arr[count] - arr[index_buy];
				index_sale = count;
				better_Rev = 1;
			}

			++count;
		}

		if (better_Rev == 1)
		{
			*buy = index_buy;
			*sale = index_sale;
		}

		index_buy = count;
		index_sale = count + 1;

		++count;
		better_Rev = 0;
	}
}

double* input_array_dyn(int n)
{
	int i;
	double*arr = (double*)malloc(n * sizeof(double));

	printf("\n");
	printf("Enter stock's values:\n");
	for (i = 0; i < n; i++)
	{
		printf("stock[%d] = ", i);
		scanf("%lf", &arr[i]);
	}
	printf("\n");

	return arr;
}