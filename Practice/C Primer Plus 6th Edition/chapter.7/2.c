// ch07ex02.c

/* Write a program that reads input until encountering #. Have the program print each input character & its ASCII decimal code. Print eight character-code pairs per line. Suggestion: Use a character count & the modulus operator (%) to print a newline character for every eight cycles of the loop. */

#include <stdio.h>

#define STOP '#'

int main(void)
{
	char ch;
	int i = 8;
	
	printf("Enter text to be analyzed (# to terminate):\n");
		
	while ((ch = getchar()) != STOP)
	{
		if (i == 8)
		{
			i = 0;
            printf("\n");
		}
		
		printf("%c: %d |  ", ch, ch);	// %c prints char, %d prints ASCII code
        i++;
	}
	
	getch();
	return 0;
}