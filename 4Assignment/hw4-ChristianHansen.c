#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw4-ChristianHansen.h"
//Christian Hansen

void sort(char **words, int totalSize)
{
	char *tempWord;
	int i;
	int j;

	for(i = 0; i < totalSize; i++)
	{
		for(j = i + 1; j < totalSize; j++)
		{
			//Compare strings (ignoring case, to match assignment 2)
			if(strcasecmp(words[i], words[j]) > 0)
			{
				//Swap words[i] with words[j] if words[j] comes first alphabetically
				tempWord = words[i];
				words[i] = words[j];
				words[j] = tempWord;
			}
		}
	}
}

int main(void)
{
	FILE *input0 = fopen("american0.txt", "r");
	FILE *input1 = fopen("american1.txt", "r");
	FILE *input2 = fopen("american2.txt", "r");

	int size0 = foo("american0.txt");
	int size1 = foo("american1.txt");
	int size2 = foo("american2.txt");
	int totalSize = size0 + size1 + size2;
	int i;
	int index = 0;
	char tempWord[50];

	char **words = malloc(totalSize * sizeof(char *));

	if(words != NULL)
	{
		for(i = 0; i < totalSize; i++)
		{
			fscanf(input0, "%s\n", tempWord);

			words[i] = malloc(sizeof(tempWord - 1));
		}
	}

	//Return pointer to beginning of each file
	fseek(input0, 0, SEEK_SET);
	fseek(input1, 0, SEEK_SET);
	fseek(input2, 0, SEEK_SET);

	//Scan file0 into the array
	for(i = 0; i < size0; i++)
	{
		//Ensure we aren't at the end of the file, then read a value in if we aren't
		if(!feof(input0))
       		{
            		fscanf(input0, "%s\n", words[index]);
            		index++;
       		}
       		else
            		break;
	}

	//Scan file0 into the array
	for(i = 0; i < size1; i++)
	{
		//Ensure we aren't at the end of the file, then read a value in if we aren't
		if(!feof(input1))
       		{
            		fscanf(input1, "%s\n", words[index]);
            		index++;
       		}
       		else
            		break;
	}

	//Scan file0 into the array
	for(i = 0; i < size2; i++)
	{
		//Ensure we aren't at the end of the file, then read a value in if we aren't
		if(!feof(input2))
       		{
            		fscanf(input2, "%s\n", words[index]);
            		index++;
       		}
       		else
            		break;
	}

	sort(words, totalSize);

	//Call bar function to print the array to output
	bar("words.txt", totalSize, words);

	//Free memory from each spot in the array
	for(i = 0; i < totalSize; i++)
	{
		free(words[i]);
	}

	//Free the array itself
	free(words);

	//Close files
	fclose(input0);
	fclose(input1);
	fclose(input2);

	return 0;
}
