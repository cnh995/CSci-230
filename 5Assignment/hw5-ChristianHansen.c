#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Christian Hansen

struct _data
{
	char *name;
	long number;
};

int error()
{
	printf("*******************************************\n");
	printf("* You must include a name to search for.  *\n");
	printf("*******************************************\n");

	return 1;
}

int SCAN(FILE *(*stream))
{
	int size = 0;
	*stream = fopen("hw5.data", "r");
	char *buffer;
	size_t bufsize = 32;
	size_t temp = getline(&buffer, &bufsize,*stream);

	//Increment size for each line break until the end of the file
	while(!feof(*stream))
	{
		size++;
		
		temp = getline(&buffer, &bufsize, *stream);
	}

	return size;
}

struct _data *LOAD(FILE *stream, int size)
{
	struct _data *dynamicArray = malloc(size * sizeof(struct _data));
	int i;	
	char* tempString;

	fseek(stream, 0, SEEK_SET);

	for(i = 0; i < size; i++)
	{
		fscanf(stream, "%s", &*tempString);
		dynamicArray[i].name = malloc(strlen(tempString) * sizeof(char));
	}

	fseek(stream, 0, SEEK_SET);

	for(i = 0; i < size; i++)
	{
		fscanf(stream, "%s %li", &*dynamicArray[i].name, &dynamicArray[i].number);
	}

	return dynamicArray;
}

void SEARCH(struct _data *BlackBox, char *name, int size)
{
	int i;
	int found = 0;

	for(i = 0; i < size; i++)
	{
		if(strcmp(name, BlackBox[i].name) == 0)
		{
			printf("*******************************************\n");
			printf("The name %s was found at the %i entry.\n", name, i);
			printf("*******************************************\n");
			found = 1;
		}
	}

	if(found == 0)
	{
		printf("*******************************************\n");
		printf("The name %s was NOT found.\n", name);
		printf("*******************************************\n");
	}
}

void FREE(struct _data *BlackBox, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		free(BlackBox[i].name);
	}

	free(BlackBox);
}


int main(int argv, char **argc)
{
	if(argv < 2 || argc == NULL)
	{
		error();
	}

	FILE *inputFile = fopen("hw5.data", "r");
	int fileSize = SCAN(&inputFile);
	int i;
	struct _data *BlackBox;
	BlackBox = LOAD(inputFile, fileSize);

	for(i = 1; i < argv; i++)
	{
		SEARCH(BlackBox, argc[i], fileSize);
	}

	
	FREE(BlackBox, fileSize);
	fclose(inputFile);
	return 0;
}
