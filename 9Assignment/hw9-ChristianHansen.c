#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Christian Hansen

struct myTree
{
	char *first;
	char *last;
	long number;
        struct myTree *right, *left;
};

typedef struct myTree node;

int SCAN(FILE *(*stream))
{
	int size = 0;
	*stream = fopen("hw9.data", "r");
	char *buffer;
	size_t bufsize = 32;
	size_t temp = getline(&buffer, &bufsize,*stream);

	//Increment size for each line break until the end of the file
	while(!feof(*stream))
	{
		size++;
		
		temp = getline(&buffer, &bufsize, *stream);
	}

	close(stream);

	return size;
}

void INSERT(node *(*tree), node *item)
{
	if(!*tree)
	{
		*tree = item;
		return;
	}
	else
	{
		if(strcmp((*tree)->first, item->first) < 0)
		{ printf("\n\ncomp: %s to %s %i\n\n", (*tree)->first, item->first, strcmp((*tree)->first, item->first));
			INSERT(&(*tree)->left, item);
		}
		else
		{printf("\n\ncomp: %s to %s %i\n\n", (*tree)->first, item->first, strcmp((*tree)->first, item->first));
			INSERT(&(*tree)->right, item);
		}
	}
}

void LOAD(FILE *stream, int size, node *(*root))
{
	int i;
	char *tempText = NULL;
	size_t lineLen;
	node *item = (node *)malloc(sizeof(node));

	rewind(stream);

	for(i = 0; i < size; i++)
	{
		getline(&tempText, &lineLen, stream);
		item->first = strdup(strtok(tempText, " "));
		item->last = strdup(strtok(NULL, " "));
		item->number = (long)strtok(NULL, "\n");

		printf("\n\n%s\n\n", item->first);
		if(i == 0){
			*root = item;}
		//INSERT(root, item);

		printf("\n\nroot %s\n\n", (*root)->first);
	}
}

void PRE_ORDER(node *tree)
{
        node *curr = tree;
	
	while(&curr != NULL)
	{
                curr = curr->left;
	}
}

void IN_ORDER(node *tree)
{
        node *curr = tree;
	
	while(&curr != NULL)
	{
                curr = curr->left;
	}
}

void POST_ORDER(node *tree)
{
        node *curr = tree;
	
	while(&curr != NULL)
	{
                curr = curr->left;
	}
}

void FREE(node *tree)
{
  
}



int main(void) {
       int size;
       FILE *stream;
       node *tree = NULL;
       
       size = SCAN(&stream);
       LOAD(stream, size, &tree);
       
       system("clear");
       
       printf("\nPRE_ORDER\n");
       printf("--------------\n");
       PRE_ORDER(tree);
       
       printf("\nIN_ORDER\n");
       printf("--------------\n");
       IN_ORDER(tree);
       
       printf("\nPOST_ORDER\n");
       printf("--------------\n");
       POST_ORDER(tree);
       
       FREE(tree);
       tree = NULL;

       return 0;
}
