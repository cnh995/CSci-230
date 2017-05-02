#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hw11-ChristianHansen-A.h"

//Christian Hansen

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


