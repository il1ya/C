// ch06ex18.c

/* Professor Dunbar joined a social media group. Initially he had five friends. He noticed that his friend count grew in the following fashion. The first week one friend dropped out & the remaining number of friends doubled. The second week two friends dropped out & the remaining number of friends doubled. In general, in the Nth week, N friends dropped out & the remaining number doubled. Write a program that computes & displays the number of friends each week. The program should continue until the count exceeds Dunbar's number. Dunbar's number is a rough estimate of the maximum size of a cohesive social group in which each member knows every other member & how they relate to one another. Its approximate value is 150. */

#include <stdio.h>
#include <math.h>

int main(void)
{
	const int initNumPals = 5, maxNumPals = 150;
	int numPals;
	
	// Hint: double exp(double x) returns the value of e raised to the xth power.
	
	for (j = initNumPals; j <= maxNumPals; j++)
	{
		for (i = j; i <= maxNumPals; i++)
		{
			week++;
			numPals = 
		}
	}
	
	getch();
	return 0;
}