#include <stdio.h>

//Christian Hansen

int main (void)
{
	float r = .22; //Interest rate
	float b = 5000; //Amount borrowed (or amount left to be paid back)
	float p = 0; //Payment amount
	float interestAmount = 0; //Amount of interest added per month
	float interestTotal = 0; //Total amount of interest paid
	int i = 1; //Counter for number of months

	while(p < b * (r / 12)) //This loop ensures we don't run into infinite loops
	{
		printf("Enter your monthly payment amount: ");
		scanf("%f", &p);
		printf("\n");

		if(p < b * (r / 12))
		{
			//Payments must be enough each month to at least pay off interest, otherwise we loop forever
			printf("Monthly payment is lower than the interest, you will never stop paying\n");
			printf("Please enter a monthly payment that is greater than %0.2f\n\n", b * (r / 12));
		}
	}

	printf("r = %0.2f\n", r);
	printf("B = %0.2f\n", b);
	printf("P = %0.2f\n\n", p);

	while(b > 0)
	{
		printf("%i ", i);

		interestAmount = (r / 12) * b; //Calculate interest for this month
		interestTotal += interestAmount; //Total up amount of interest being paid
		
		printf("%0.2f ", interestAmount); //Showing how much interest was added
		printf("%0.2f\n", b); //Showing how much is left to be paid off
		
		b = b - p + interestAmount; //Calculates how much is left to be paid after this month

		i++; //Increment month
	}
	
	printf("\nTotal interest paid: %0.2f\n", interestTotal);

	return 0;
}

