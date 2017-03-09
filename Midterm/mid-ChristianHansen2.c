#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Christian Hansen

struct _data
{
	char *fName;
	char *lName;
	long number;
};

int tooFewError()
{
	printf("*******************************************\n");
	printf("* You must include a name to search for.  *\n");
	printf("*******************************************\n");

	return 1;
}

int tooManyError()
{
	printf("*******************************************\n");
	printf("* Too many arguments entered.  *\n");
	printf("*******************************************\n");

	return 1;
}

int SCAN(FILE *(*stream))
{
	int size = 0;
	*stream = fopen("midterm.data", "r");
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
	char* tempFName = NULL;
	char* tempLName = NULL;
	size_t lineLen;

	fseek(stream, 0, SEEK_SET);

	for(i = 0; i < size; i++)
	{
		lineLen = getline(&tempFName, &lineLen, stream);

		dynamicArray[i].fName = malloc(lineLen * sizeof(char));
		dynamicArray[i].lName = malloc(lineLen * sizeof(char));
	}



	fseek(stream, 0, SEEK_SET);

	for(i = 0; i < size; i++)
	{
		fscanf(stream, "%s %s %li", &*dynamicArray[i].fName, dynamicArray[i].lName, &dynamicArray[i].number);
	}

	return dynamicArray;
}

void SEARCH(struct _data *BlackBox, char *fName, char *lName, int size)
{
	int i;
	int found = 0;

	if(lName != NULL)
	{
		for(i = 0; i < size; i++)
		{
			if(strcmp(fName, BlackBox[i].fName) == 0 && strcmp(lName, BlackBox[i].lName) == 0)
			{
					printf("*******************************************\n");
					printf("The name %s %s was found at the %i entry.\n", fName, lName, i);
					printf("*******************************************\n");
					found = 1;
					break;

			}
		}
	

		if(found == 0)
		{
			printf("*******************************************\n");
			printf("The name %s %s was NOT found.\n", fName, lName);
			printf("*******************************************\n");
		}
	}
	else
	{
		for(i = 0; i < size - 1; i++)
		{
			if(strcmp(fName, BlackBox[i].fName) == 0)
			{
				printf("*******************************************\n");
				printf("The name %s was found at the %i entry.\n", fName, i);
				printf("*******************************************\n");
				found = 1;
				break;
			}
		}
	

		if(found == 0)
		{
			printf("*******************************************\n");
			printf("The name %s was NOT found.\n", fName);
			printf("*******************************************\n");
		}
	}
}

void FREE(struct _data *BlackBox, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		free(BlackBox[i].fName);
		free(BlackBox[i].lName);
	}

	free(BlackBox);
}


int main(int argv, char **argc)
{
	if(argv < 2 || argc == NULL)
	{
		tooFewError();
	}
	
	if(argv > 3)
	{
		tooManyError();
	}

	FILE *inputFile = fopen("midterm.data", "r");
	int fileSize = SCAN(&inputFile);
	int i;
	struct _data *BlackBox;
	BlackBox = LOAD(inputFile, fileSize);

	if(argv == 3)
	{
		SEARCH(BlackBox, argc[i + 1], argc[i + 2], fileSize);
	}
	else
	{
		SEARCH(BlackBox, argc[i + 1], NULL, fileSize);
	}
	
	FREE(BlackBox, fileSize);
	fclose(inputFile);
	return 0;
}
