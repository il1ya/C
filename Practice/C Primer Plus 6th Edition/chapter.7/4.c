// ch07ex04.c

/* Using if else statements, write a program that reads input up to #, replaces each period with an exclamation mark, replaces each exclamation mark initially present with two exclamation marks, & reports at the end the number of substitutions it has made. */

#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int subSum = 0;
	printf("Enter text to be analyzed (# to terminate):\n");
	while ((ch = getchar()) != STOP)
	{
		if (ch == '.')
		{
			ch = '!';
			++subSum;
		} else if (ch == '!') {
			ch = '!' + '!';
			++subSum;
		}
	}
	printf("There were %d substitutions made.\n", subSum);
	getch();
	return 0;
}