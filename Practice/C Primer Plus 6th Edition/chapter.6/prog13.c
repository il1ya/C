// ch06ex13.c

/* Write a program that creates an eight-element array of ints & sets the elements to the first eight powers of 2 & then prints the values. Use a for loop to set the values, &, for variety, use a do while loop to display the values. */

#include <stdio.h>
int main(void)
{
	const int SIZE = 8;
 	int i, twopows[SIZE];
 	int value = 1;
	 
	for (i = 0; i < SIZE; i++)
	{
 		twopows[i] = value;
 		value *= 2;
	}

 	i = 0;
 	
	do
 	{
 		printf("%d ", twopows[i]);
 		i++;
 	} while (i < SIZE);

	getch();
	return 0;
}