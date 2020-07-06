#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int info;
	struct Node* next;
}Node;

enum SeparateStatus
{
	Separate_First_Node,
	Separate_Middle_Node,
	Separate_Last_Node
};

void Print_Node(Node* n);
void Free_Node(Node* n);
Node* BuildList();
Node* Insert(int num);
Node* createList(Node** list);
void Separate(Node** list, Node** odd_list, enum SeparateStatus ss);

void main()
{
	Node* num_list = NULL, *odd_list = NULL;

	num_list = BuildList();

	printf("\nBefore update:");
	Print_Node(num_list);

	odd_list = createList(&num_list);

	printf("\nAfter update:\n");
	printf("\nList of even numbers:");
	Print_Node(num_list);
	printf("\nList of odd  numbers:");
	Print_Node(odd_list);

	Free_Node(odd_list);
	Free_Node(num_list);
	system("PAUSE");
}

Node* createList(Node** list)
{
	int first_head_insert = 0;
	Node* odd_head = NULL, *odd_current = NULL, *list_current = *list, *list_prev = NULL;

	if (!(*list))
		return NULL;

	while ((list_current != NULL) && (list_current->info % 2 != 0))
	{
		if (first_head_insert == 0)
		{
			Separate(list, &odd_head, Separate_First_Node);
			odd_current = odd_head;
			first_head_insert = 1;
		}
		else
		{
			Separate(list, &(odd_current->next), Separate_First_Node);
			odd_current = odd_current->next;
		}

		list_current = *list;
	}

	if (list_current != NULL)
	{
		list_prev = *list;
		list_current = list_current->next;

		while (list_current->next != NULL)
		{
			if (list_current->info % 2 != 0)
			{
				if (first_head_insert == 0)
				{
					Separate(&list_prev, &odd_head, Separate_Middle_Node);
					odd_current = odd_head;
					first_head_insert = 1;
				}
				else
					Separate(&list_prev, &odd_current, Separate_Middle_Node);

				list_current = list_prev;
			}
			else
			{
				list_prev = list_current;
				list_current = list_current->next;
			}
		}

		if (list_current->info % 2 != 0)
			Separate(&list_prev, &odd_current, Separate_Last_Node);
	}

	return odd_head;
}

void Separate(Node** list, Node** odd_list, enum SeparateStatus ss)
{
	if (ss == Separate_First_Node)
	{
		Node* new_node = *list;
		*list = (*list)->next;
		*odd_list = new_node;
		(*odd_list)->next = NULL;
	}
	if (ss == Separate_Middle_Node)
	{
		Node* new_node = (*list)->next;
		(*list)->next = (*list)->next->next;

		new_node->next = NULL;

		if (*odd_list != NULL)
		{
			(*odd_list)->next = new_node;
			*odd_list = (*odd_list)->next;
		}
		else
			*odd_list = new_node;
	}
	if (ss == Separate_Last_Node)
	{
		Node* new_node = (*list)->next;
		(*list)->next = NULL;
		(*odd_list)->next = new_node;
	}
}

Node* Insert(int num)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->info = num;
	return new_node;
}

Node* BuildList()
{
	int num;
	Node* head, *current;

	printf("Enter a number:");
	scanf("%d", &num);

	if (num < 0)
		return NULL;

	head = Insert(num);
	current = head;

	while (num >= 0)
	{
		printf("Enter a number:");
		scanf("%d", &num);

		if (num >= 0)
		{
			current->next = Insert(num);
			current = current->next;
		}

	}
	current->next = NULL;

	return head;
}

void Print_Node(Node* n)
{
	if (n != NULL)
	{
		Node* to_print = n;

		printf("\n");
		while (to_print != NULL)
		{
			printf("%d -> ", to_print->info);
			to_print = to_print->next;
		}
		printf("\n");
	}
	else
		printf("\nThe list is empty\n");
}

void Free_Node(Node* n)
{
	Node* to_free = n;

	while (to_free != NULL)
	{
		n = n->next;
		free(to_free);
		to_free = n;
	}
}