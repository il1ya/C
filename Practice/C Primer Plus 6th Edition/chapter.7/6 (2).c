// ch07ex06.c

/* Write a program that reads input up to # & reports the number of times that the sequence ei occurs.
Note: The program will have to "remember" the preceding character as well as the current character. Test it with input such as "Receive your eieio award." */

#include <stdio.h>

#define STOP '#'

int main(void)
{
	char ch, chE;
	int sumEI = 0;
	
	printf("Enter text to be analyzed (# to terminate):\n");
	
	while ((ch = getchar()) != STOP)
	{
		if (ch == 'e')
		{
			chE = 'e';
		} else if (ch == 'i' && chE == 'e')
		{
			++sumEI;
		}
	}
	printf("The sequence ei occurs %d times.\n", sumEI);
	
	getch();
	return 0;
}