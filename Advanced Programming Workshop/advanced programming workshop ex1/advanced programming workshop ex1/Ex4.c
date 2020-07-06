#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int info;
	struct Node* next;
}Node;

enum DeleteStatus
{
	Delete_First_Node,
	Delete_Middle_Node,
	Delete_Last_Node
};

Node* BuildList();
Node* createList(Node** list);
void Delete(Node** list, Node* prev_delete_node, enum DeleteStatus ds);
Node* Insert(int num);
void Print_Node(Node* n);
void Free_Node(Node* n);

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

	Free_Node(num_list);
	Free_Node(odd_list);
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
			odd_head = Insert(list_current->info);
			odd_current = odd_head;
			first_head_insert = 1;
		}
		else
		{
			odd_current->next = Insert(list_current->info);
			odd_current = odd_current->next;
		}

		Delete(list, NULL, Delete_First_Node);
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
					odd_head = Insert(list_current->info);
					odd_current = odd_head;
					first_head_insert = 1;
				}
				else
				{
					odd_current->next = Insert(list_current->info);
					odd_current = odd_current->next;
				}
				Delete(&list_current, list_prev, Delete_Middle_Node);
				list_current = *list;
			}

			list_prev = list_current;
			list_current = list_current->next;
		}

		if (list_current->info % 2 != 0)
		{
			odd_current->next = Insert(list_current->info);
			odd_current = odd_current->next;
			Delete(&list_current, list_prev, Delete_Last_Node);
		}
	}
	if (first_head_insert == 1)
		odd_current->next = NULL;

	return odd_head;
}
void Delete(Node** list, Node* prev_delete_node, enum DeleteStatus ds)
{
	if (ds == Delete_First_Node)
	{
		Node* free_node = *list;
		*list = (*list)->next;
		free(free_node);
	}
	if (ds == Delete_Middle_Node)
	{
		prev_delete_node->next = (*list)->next;
		free(*list);
	}
	if (ds == Delete_Last_Node)
	{
		prev_delete_node->next = NULL;
		free(*list);
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