#include <stdio.h>
#define BOOK "War and Peace" // Война и мир
int main (void)
{
	float cost = 12.99;
	float percent = 80.0;
	printf("Data copy of the book \"%s\" cost %0.2f\r\n"
		"This %.0f%% the price in the price-list. ", BOOK, cost, percent);
	return 0;
}