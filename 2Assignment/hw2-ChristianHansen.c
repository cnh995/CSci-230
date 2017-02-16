#include <stdio.h>
#include <stdlib.h>

//Christian Hansen

int main(void)
{
	int combine = system("cat american0.txt american1.txt american2.txt > unsortedwords.txt");
	int sort = system("sort unsortedwords.txt > words.txt");
	int removeOld = system("rm unsortedwords.txt");
}
