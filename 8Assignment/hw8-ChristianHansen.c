#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Christian Hansen

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void tooManyError()
{
	printf("******************************************************\n");
	printf("Too many command line arguments given, exiting program.\n");
	printf("******************************************************\n");
}

void tooFewError()
{
	printf("******************************************************\n");
	printf("Too few command line arguments given, exiting program.\n");
	printf("******************************************************\n");
}

void insertNode(int data, struct node **head, struct node **tail)
{
	struct node *curr = malloc(sizeof(*curr));
	curr = *head;

	while(curr->next)
        {
        	curr = curr->next;
        }

	struct node *temp = malloc(sizeof(*temp));
	temp->data = data;
	curr->next = temp;
	temp->prev = curr;
	(*tail) = temp;
}

void printList(struct node *head, struct node *tail)
{
	int i;
	struct node *curr = head;

	printf("\n");
	while(curr != NULL)
	{
		printf("Left to right output: %i\t\n", curr->data);
		curr = curr->next;
	}

	curr = tail;
	printf("\n");
	while(curr != NULL)
	{
		printf("Right to left output: %i\t\n", curr->data);
		curr = curr->prev;
	}
}

int main(int argv, char **argc)
{
        if(argv > 2)
        {
        	tooManyError();
		return 0;
	}
	
	if(argv < 2)
	{
		tooFewError();
		return 0;
	}

	int n = atoi(argc[1]);
	int i;
	struct node *head = malloc(sizeof(*head));
	struct node *tail = NULL;

	for(i = 0; i <= n; i++)
	{
		if(i == 0)
		{
			head->data = i;
		}
		else
		{
			insertNode(i, &head, &tail);
		}

		printf("Input data: %i\t\t\n", i);		
	}

	printList(head, tail);
	return 0;
}
