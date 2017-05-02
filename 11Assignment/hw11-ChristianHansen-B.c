#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hw11-ChristianHansen-B.h"

//Christian Hansen

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
