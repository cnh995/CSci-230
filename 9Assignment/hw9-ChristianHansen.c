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
	char *buffer = NULL;
	size_t bufsize = 0;

	while(getline(&buffer, &bufsize, *stream) != -1)
	{
		size++;
	}

	free(buffer);
	return size;
}

void INSERT(node *(*tree), node *item)
{
	if(!*tree)
	{
		*tree = item;
		return;
	}
	
	if(strcmp((*tree)->first, item->first) < 0)
	{
		INSERT(&(*tree)->left, item);
	}
	else
	{
		INSERT(&(*tree)->right, item);
	}
}

char *strdup(const char *str)
{
	char *s = malloc(strlen(str) + 1);
	if(s)
	{
		strcpy(s, str);
	}

	return s;
}

node *newNode(char *text)
{
	node *item = malloc(sizeof(*item));

	if(item)
	{
		item->first = strdup(strtok(text, " "));
		item->last = strdup(strtok(NULL, " "));
		item->number = atol(strtok(NULL, "\n"));
		item->left = NULL;
		item->right = NULL;
	}

	return item;
}

void LOAD(FILE *stream, int size, node *(*root))
{
	char *tempText = NULL;
	size_t lineLen = 0;

	rewind(stream);

	while(getline(&tempText, &lineLen, stream) != -1)
	{
		node *item = newNode(tempText);
		INSERT(root, item);
	}
	
	fclose(stream);
	free(tempText);
}

void PRE_ORDER(node *tree)
{
	if(tree == NULL)
	{
		return;
	}
	
	printf("%s\n", tree->first);

	PRE_ORDER(tree->left);
	PRE_ORDER(tree->right);
}

void IN_ORDER(node *tree)
{
        if(tree == NULL)
	{
		return;
	}

	IN_ORDER(tree->left);

	printf("%s\n", tree->first);

	IN_ORDER(tree->right);
}

void POST_ORDER(node *tree)
{
        if(tree == NULL)
	{
		return;
	}

	POST_ORDER(tree->left);
	POST_ORDER(tree->right);

	printf("%s\n", tree->first);
}

void FREE(node *tree)
{
	if(tree == NULL)
	{
		return;
	}

	FREE(tree->left);
	FREE(tree->right);

	free(tree->first);
	free(tree->last);
	free(tree);
}

int main(void)
{
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
