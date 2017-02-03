#include <stdio.h>
#include <stdlib.h>

//Christian Hansen

int file_size(FILE *inputFile)
{
	int size = 0;
	char temp = fgetc(inputFile);

	//Increment size for each line break until the end of the file
	while(temp != EOF)
	{
		if(temp == '\n')
			size++;
		
		temp = fgetc(inputFile);
	}

	return size;	
}

void sort(int *numbers, int totalSize)
{
	int *tempArray = numbers;
	int tempNumber;
	int i;
	int j;

	for(i = 0; i < totalSize; i++)
	{
		for(j = i + 1; j < totalSize; j++)
		{
			if(numbers[i] > numbers[j])
			{
				//Swap number[i] with number[j] if number[i] is the larger of the two
				tempNumber = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tempNumber;
			}
		}
	}
}

int main(void)
{
	//Open files for input and output
	FILE *file0 = fopen("list0.txt", "r");
	FILE *file1 = fopen("list1.txt", "r");
	FILE *file2 = fopen("list2.txt", "r");
	FILE *output = fopen("hw3.out", "w");

	//Get file size (number of lines)
	long size0 = file_size(file0);
	long size1 = file_size(file1);
	long size2 = file_size(file2);

	//Find the total number of lines in the three files
	long totalSize = size0 + size1 + size2;
	
	//Allocate memory for the number of lines for dynamically sized array
	int *numbers = malloc(totalSize * sizeof(int));

	int i;
	int index = 0;
	char temp;

	//Return pointer to beginning of each file
	fseek(file0, 0, SEEK_SET);
	fseek(file1, 0, SEEK_SET);
	fseek(file2, 0, SEEK_SET);

	//Scan file0 into the array
	for(i = 0; i < size0; i++)
	{
		//Ensure we aren't at the end of the file, then read a value in if we aren't
		if(!feof(file0))
       		{
            		fscanf(file0, "%i", &numbers[index]);
            		index++;
       		}
       		else
            		break;
	}

	//Scan file1 into the array
	for(i = 0; i < size1; i++)
	{
		//Ensure we aren't at the end of the file, then read a value in if we aren't
		if(!feof(file1))
       		{
            		fscanf(file1, "%i", &numbers[index]);
            		index++;
       		}
       		else
            		break;
	}

	//Scan file2 into the array
	for(i = 0; i < size2; i++)
	{
		//Ensure we aren't at the end of the file, then read a value in if we aren't
		if(!feof(file2))
       		{
			
			fscanf(file2, "%i", &numbers[index]);
            		index++;
       		}
       		else
            		break;
	}

	//Sort the array
	sort(numbers, totalSize);

	//Print sorted array to output file
	for(i = 0; i < totalSize; i++)
	{
		fprintf(output, "%i\n", numbers[i]);
	}
	
	//Close files
	fclose(file0);
	fclose(file1);
	fclose(file2);
	fclose(output);

	//Free the allocated memory
	free(numbers);

	return 0;
}


