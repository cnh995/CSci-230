#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hw11-ChristianHansen-D.h"

//Christian Hansen

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
