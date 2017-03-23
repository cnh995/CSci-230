#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Christian Hansen

struct node
{
	char name[42];
	struct node *next;
};

void insertNode(char name[42], struct node **head)
{
	while(*head && strcmp((*head)->name, name) < 0)
    {
        head = &(*head)->next;
    }

    struct node *temp = malloc(sizeof(*temp));
    strcpy(temp->name, name);
    temp->next = *head;
    *head = temp;
}

void removeNode(char name[42], struct node **head)
{
	int done = 0;

    while(*head && (done = strcmp((*head)->name, name)) < 0)
        head = &(*head)->next;

    if(head && (done == 0))
    {
        struct node *temp = *head;
        *head = temp->next;
    }
}

void FREE(struct node **head)
{
	while(*head)
	{
		struct node *temp = *head;
		*head = temp->next;
		free(temp);
	}
}


void printList(struct node *head)
{
	printf("Linked list:\n");
	for(; head; head = head->next)
	{
		printf("%s\n", head->name);
	}
}

int main(void)
{
	FILE *input = fopen("hw7.data", "r");
    if(!input)
    {
        printf("Error opening file");
        return 0;
    }

	struct node *head = NULL;
	
	char *tempText = NULL;
	char *tempName = NULL;
	char *tempOP = NULL;

	size_t lineLen;
	

	while(getline(&tempText, &lineLen, input) > 0)
	{
		tempName = strtok(tempText, " ");
		tempOP = strtok(NULL, "\n");

		if(*tempOP == 'a')
		{
			insertNode(tempName, &head);
		}
		else if(*tempOP == 'd')
		{
			removeNode(tempName, &head);
		}
	}
    free(tempText);
	printList(head);
	fclose(input);
	FREE(&head);
	return 0;
}
