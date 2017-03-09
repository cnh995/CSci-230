#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Christian Hansen

struct _data
{
	char *first;
	char *middle;
	char *last;
	long number;
};

int tooFewError()
{
	printf("*************************************************\n");
	printf("*         Not enough arguments entered.         *\n");
	printf("*    When searching for just first and last:    *\n");
	printf("*  you must enter \"_\" (without quotation marks) *\n");
	printf("*                 as a middle name.             *\n");
	printf("*************************************************\n");

	return 1;
}

int tooManyError()
{
	printf("*******************************************\n");
	printf("*       Too many arguments entered.       *\n");
	printf("*******************************************\n");

	return 1;
}

int SCAN(FILE *(*stream))
{
	int size = 0;
	*stream = fopen("hw6.data", "r");
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
	char *tempFName = NULL;
	char *tempMName = NULL;
	char *tempLName = NULL;
	char *tempPhone = NULL;
	char *tempText = NULL;
	size_t lineLen;

	rewind(stream);

	for(i = 0; i < size - 1; i++)
	{
		getline(&tempText, &lineLen, stream);
		tempFName = strtok(tempText, " ");
		tempMName = strtok(NULL, " ");
		tempLName = strtok(NULL, " ");
		tempPhone = strtok(NULL, "\n");

		dynamicArray[i].first = (char*)calloc(strlen(tempFName) + 1, sizeof(char));
		dynamicArray[i].middle = (char*)calloc(strlen(tempMName) + 1, sizeof(char));
		dynamicArray[i].last = (char*)calloc(strlen(tempLName) + 1, sizeof(char));

		strcpy(dynamicArray[i].first, tempFName);
		strcpy(dynamicArray[i].middle, tempMName);
		strcpy(dynamicArray[i].last, tempLName);
	}

	return dynamicArray;
}

void SEARCH(struct _data *BlackBox, char *fName, char *mName, char *lName, int size)
{
	int i;
	int found = 0;

	if(lName != NULL)
	{
		if(mName == NULL)
		{
			for(i = 0; i < size - 1; i++)
			{
				if(strcmp(fName, BlackBox[i].first) == 0 && strcmp(lName, BlackBox[i].last) == 0)
				{
						printf("*******************************************\n");
						printf("The name %s %s was found at the %i entry.\n", fName, lName, i);
						printf("*******************************************\n");
						found = 1;
						break;
				}
			}
		}
		else	
		{
			for(i = 0; i < size - 1; i++)
			{
				if(strcmp(fName, BlackBox[i].first) == 0 && strcmp(mName, BlackBox[i].middle) == 0 && strcmp(lName, BlackBox[i].last) == 0)
				{
						printf("*******************************************\n");
						printf("The name %s %s %s was found at the %i entry.\n", fName, mName, lName, i);
						printf("*******************************************\n");
						found = 1;
						break;
				}
			}
		}

		if(found == 0)
		{
			printf("*******************************************\n");
			printf("The name %s %s %s was NOT found.\n", fName, mName, lName);
			printf("*******************************************\n");
		}
	}
	else
	{
		for(i = 0; i < size - 1; i++)
		{
			if(strcmp(fName, BlackBox[i].first) == 0)
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
		free(BlackBox[i].first);
		free(BlackBox[i].middle);
		free(BlackBox[i].last);
	}

	free(BlackBox);
}


int main(int argv, char **argc)
{
	if(argv < 2 || argc == NULL)
	{
		tooFewError();
		return 0;
	}

	if(argv == 3)
	{
		tooFewError();
		return 0;
	}
	
	if(argv > 4)
	{
		tooManyError();
		return 0;
	}

	FILE *inputFile = fopen("hw6.data", "r");
	int fileSize = SCAN(&inputFile);
	struct _data *BlackBox;
	BlackBox = LOAD(inputFile, fileSize);

	if(argv == 4 && argc[2][0] != '_')
	{
		SEARCH(BlackBox, argc[1], argc[2], argc[3], fileSize);
	}
	else if(argv == 4 && argc[2][0] == '_')
	{
		SEARCH(BlackBox, argc[1], NULL, argc[3], fileSize);
	}
	else if(argv == 2)
	{
		SEARCH(BlackBox, argc[1], NULL, NULL, fileSize);
	}
	
	FREE(BlackBox, fileSize);
	fclose(inputFile);
	return 0;
}
