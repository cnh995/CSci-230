#include <stdio.h>
#include <stdlib.h>
//Christian Hansen

int foo(char *filename)
{
	FILE *input = fopen(filename, "r");

	int size = 0;

	char temp = fgetc(input);

	//Increment size for each line break until the end of the file
	while(temp != EOF)
	{
		if(temp == '\n')
			size++;
		
		temp = fgetc(input);
	}

	fclose(input);

	return size;
}
