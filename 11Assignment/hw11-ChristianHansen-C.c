#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hw11-ChristianHansen-C.h"

//Christian Hansen

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

void DISPLAY_TRASH(struct node *head, struct node *tail)
{
    printf("\n\nTrash Inorder:\n");
    DISPLAY_INORDER(head, tail);
	printf("\nTrash Postorder:\n");
    DISPLAY_POSTORDER(head, tail);

    FREE_INORDER(head, tail);
}
