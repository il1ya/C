// ch06ex04.c

/* Use nested loops to produce the following pattern:
A			
BC			
DEF
GHIJ
KLMNO
PQRSTU
If your system doesn't encode letters in numeric order, see the suggestion in programming exercise 3. */
#include <stdio.h>
int main(void)
{
	const char m = 'U';					// Maximum character value.
	char i, j;
	char k = 'A';
	for (j = k; k <= m; j++)			// For A; while A <= U; run inner loop & increment.
	{
		for (i = 'A'; i <= j; i++)		// For A; while A <= U; print char & increment.
		{
			printf("%c", k);			// Print current value for k (should be between A & U).
			k++;						// Increment value for k.
		}
		printf("\n");					// Print new line each time inner loop exits.
	}
	getch();	// This is used to prevent the console window from closing on some systems.
	return 0;
}