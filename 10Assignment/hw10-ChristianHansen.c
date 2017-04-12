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

void insertNode(struct node *item, struct node **head, struct node **tail)
{
	if(!*head)
	{
		*head = item;
		return;
	}
	
	insertNode(item, &(*head)->next, tail);
}

void DISPLAY_INORDER(struct node *head, struct node *tail)
{
	if(head == NULL)
	{
		return;
	}

    if(head != tail)
    {
	    DISPLAY_INORDER(head->prev, tail);
    }

	printf("%i\n", head->data);

    if(head != tail)
    {
	    DISPLAY_INORDER(head->next, tail);
    }
}

void DISPLAY_POSTORDER(struct node *head, struct node *tail)
{
	if(head == NULL)
	{
		return;
	}

    if(head != tail)
    {
	    DISPLAY_POSTORDER(head->prev, tail);
	    DISPLAY_POSTORDER(head->next, tail);
    }

	printf("%i\n", head->data);
}

void FREE_INORDER(struct node *head, struct node *tail)
{
    if(head == NULL)
	{
		return;
	}

    if(head != tail)
    {
	    FREE_INORDER(head->prev, tail);
    }

	free(&head->data);

    if(head != tail)
    {
    	FREE_INORDER(head->next, tail);
    }

	free(head);
}

void DISPLAY_TRASH(struct node *head, struct node *tail)
{
    printf("\nTrash Display:\n");
    DISPLAY_INORDER(head, tail);
    DISPLAY_POSTORDER(head, tail);

    printf("\nFreeing Trash...\n");
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
	struct node *head = malloc(sizeof(*head));
	struct node *tail = NULL;
    struct node *trashHead = malloc(sizeof(*head));
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


    printf("\nInorder:\n");
	DISPLAY_INORDER(head, tail);
    printf("\nPostorder:\n");
    DISPLAY_POSTORDER(head, tail);
    //DISPLAY_TRASH(trashHead, trashTail);

    FREE_INORDER(head, tail);
	return 0;
}
