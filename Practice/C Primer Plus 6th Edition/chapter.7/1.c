// ch07ex01.c

/* Write a program that reads input until encountering the # character & then reports the number of spaces read, the number of newline characters read, & the number of all other characters read. */

#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int n_spaces = 0;
	int n_lines = 0; 
	int n_others = 0;
	printf("Enter text to be analyzed (# to terminate):\r\n");
	while ((ch = getchar()) != STOP)
	{
		if (!isspace(ch))
			n_spaces++;
		else if (ch == '\n')
			n_lines++;
		else
			n_others++;
	}
	
	printf("spaces: %d, lines: %d, others: %d\n", n_spaces, n_lines, n_others);
	
	getch();
	return 0;
}