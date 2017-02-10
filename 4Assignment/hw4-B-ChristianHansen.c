#include <stdio.h>
#include <stdlib.h>
//Christian Hansen

void bar(char *filename, int total, char **words)
{
	FILE *output = fopen(filename, "w");

	int i;

	//Print each word
	for(i = 0; i < total; i++)
	{
		fprintf(output, "%s\n", words[i]);
	}

	fclose(output);
}
