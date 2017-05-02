#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dlfcn.h>

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

	void* hw11_lib_ChristianHansen;
	hw11_lib_ChristianHansen = dlopen("./hw11-lib-ChristianHansen.so", RTLD_NOW);
	if(!hw11_lib_ChristianHansen)
	{
		printf("\n%s\n", dlerror());
		exit(1);
	}

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
