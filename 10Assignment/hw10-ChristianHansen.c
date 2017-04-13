#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void insertNode(struct node *item, struct node **head, struct node **tail)
{
	if(!*head)
	{
		(*head) = item;
		(*head)->prev = NULL;
		(*tail) = item;
		(*tail)->next = NULL;
		return;
	}
	
	struct node *curr = *head;
	struct node *temp = malloc(sizeof(*temp));

	while(curr->next != NULL)
	{
		curr = curr->next;
	}

	temp = item;
	curr->next = temp;
	temp->prev = curr;
	(*tail) = temp;
}

void DISPLAY_INORDER(struct node *head, struct node *tail)
{
	if(head == NULL)
	{
		return;
	}

	struct node *curr = head;

    while(curr != NULL)
    {
		printf("%i\n", curr->data);
		curr = curr->next;
    }
}

void DISPLAY_POSTORDER(struct node *head, struct node *tail)
{
	if(head == NULL)
	{
		return;
	}

	struct node *curr = tail;

    while(curr != NULL)
    {
		printf("%i\n", curr->data);
		curr = curr->prev;
    }
}

void FREE_INORDER(struct node *head, struct node *tail)
{
    if(head == NULL)
	{
		return;
	}

	printf("\n");

	struct node *curr = head;

    while(curr != NULL)
    {
		if(curr != tail)
		{
			curr = curr->next;
		}

		if(curr != NULL && curr != tail)
		{
			free(curr->prev);
		}

		if(curr == tail)
		{
			free(curr->prev);
			free(curr);
			break;
		}
    }
}

void DELETE_NODE(int numToDelete, struct node **head, struct node **tail, struct node **trashHead, struct node **trashTail)
{
	int i;
	int j;
	struct node *curr = malloc(sizeof(curr));
	struct node *temp = malloc(sizeof(temp));

	for(i = numToDelete; i > 0; i--)
	{
		int nodeToDelete = rand() % i;
printf("\nDeleting node at index: %i", nodeToDelete);
		j = 0;
		curr = *head;

		while(curr != NULL)
		{
			if(j == nodeToDelete)
			{
				if(curr == (*head))
				{
					if(curr->next != NULL)
					{
						(*head) = curr->next;
						(*head)->prev = NULL;
						curr->next = NULL;
						insertNode(curr, &*trashHead, &*trashTail);
						break;
					}
					else
					{
						(*head) = NULL;
						curr->next = NULL;
						insertNode(curr, &*trashHead, &*trashTail);
						break;
					}
				}
				else if(curr == (*tail))
				{
					(*tail) = curr->prev;
					(*tail)->next = NULL;
					curr->prev = NULL;
					insertNode(curr, &*trashHead, &*trashTail);
					break;
				}
				else
				{
					temp = curr->prev;
					temp->next = curr->next;
					temp = curr->next;
					temp->prev = curr->prev;
					curr->prev = NULL;
					curr->next = NULL;
					insertNode(curr, &*trashHead, &*trashTail);
					break;
				}
			}			
			j++;
			curr = curr->next;
		}
	}
}

void DISPLAY_TRASH(struct node *head, struct node *tail)
{
    printf("\n\nTrash Inorder:\n");
    DISPLAY_INORDER(head, tail);
	printf("\nTrash Postorder:\n");
    DISPLAY_POSTORDER(head, tail);

    FREE_INORDER(head, tail);
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
	struct node *head = NULL;
	struct node *tail = NULL;
    struct node *trashHead = NULL;
    struct node *trashTail = NULL;

	for(i = 0; i <= n; i++)
	{
        struct node *item = malloc(sizeof(*item));
        item->data = i;
        item->next = NULL;
        item->prev = NULL;

		insertNode(item, &head, &tail);
		
		printf("Input data: %i\t\t\n", i);		
	}

	srand(time(NULL));
	int numToDelete = rand() % (atoi(argc[1]) + 2);
	printf("\nDeleting %i node(s)...\n", numToDelete);

	DELETE_NODE(numToDelete, &head, &tail, &trashHead, &trashTail);

	if(trashHead != NULL)
	{
    	DISPLAY_TRASH(trashHead, trashTail);
	}

    printf("\n\nInorder:\n");
	DISPLAY_INORDER(head, tail);
    printf("\nPostorder:\n");
    DISPLAY_POSTORDER(head, tail);
	printf("\n");

    FREE_INORDER(head, tail);
	return 0;
}
