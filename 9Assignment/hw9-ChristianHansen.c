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
        node *curr = *tree;
	int inserted = 0;

	while(inserted == 0)
	{
	        if(strcmp(item->first, (*tree)->first) > 0 && curr->left != NULL )
	        {
	                curr = curr->left;
			if(curr->left == NULL)
			{
  			        curr->left = item;
				inserted = 1;
			}
	        }
	        else if(strcmp(item->first, (*tree)->first) < 0 && curr->right != NULL)
	        {
	                curr = curr->right;
			if(curr->right == NULL)
			{
  			        curr->right = item;
				inserted = 1;
			}
                }
		else
		{
		        if(curr->right != NULL)
			{
   			        curr = curr->right;
				if(curr->right == NULL)
				{
				        curr->right = item;
				        inserted = 1;
				}
			}
			else
			{
			        curr->right = item;
				inserted = 1;
			}
		}
	}
	
}

void LOAD(FILE *stream, int size, node *(*root))
{
	int i;
	int result;
	char *tempFName = NULL;
	char *tempLName = NULL;
	char *tempPhone = NULL;
	char *tempText = NULL;
	size_t lineLen;
	node *item = malloc(sizeof(node));

	rewind(stream);

	for(i = 0; i < size; i++)
	{
		getline(&tempText, &lineLen, stream);
		tempFName = strtok(tempText, " ");
		tempLName = strtok(NULL, " ");
		tempPhone = strtok(NULL, "\n");

		printf("\nname: %s\n", tempFName);

		item->first = (char*)calloc(strlen(tempFName) + 1, sizeof(char));
		item->last = (char*)calloc(strlen(tempLName) + 1, sizeof(char));
		
		strcpy(item->first, tempFName);
		strcpy(item->last, tempLName);
		item->number = (long)tempPhone;

		printf("\ni: %i\n", i);
		
		if(i == 0)
		{
		        *root = item;
		}
		else
		{
		        INSERT(&*root, item);
		}
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
