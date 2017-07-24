// ch06ex05.c

/* Have a program request the user to enter an uppercase letter. Use nested loops to produce a pyramid pattern like this:
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
The pattern should extend to the character entered. For example, the preceding pattern would result from an input value of E. Hint: Use an outer loop to handle the rows. Use three inner loops in a row, one to handle the spaces, one for printing letters in ascending order, & one for printing letters in descending order. If your system doesn't use ASCII or a similar system that represents letters in strict number order, see the suggeston in programming exercise 3. */

#include <stdio.h>

int main(void)
{
	const char n = 'A';
	char letter;
	char i, j, k, m;
	
	printf("Enter an uppercase letter: ");
	scanf("%c", &letter);
	
	for (i = n; i <= letter; i++)		// rows
	{
		for (j = letter; j >= i; j--)	// spaces
		{
			printf("-");
		}
		for (k = n; k <= i; k++)		// letters, ascending
		{
			printf("%c", k);
		}
		for (m = k - 2; m >= n; m--)			// letters, descending
		{
			printf("%c", m);
		}
		printf("\n");
	}
	
	getch();	// This is used to prevent the console window from closing on some systems.
	return 0;
}