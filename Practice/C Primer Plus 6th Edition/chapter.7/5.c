// ch05ex05.c

// Redo exercise 4 using switch.

#include <stdio.h>

#define STOP '#'

int main(void)
{
	char ch;
	int subSum1 = 0;
	int subSum2 = 0;
	
	printf("Enter text to be analyzed (# to terminate):\n");
	
	while ((ch = getchar()) != STOP)
	{
		switch(ch)
		{
			case '.' : 	putchar('!');
						++subSum1;
						break;
			case '!' : 	putchar('!');
						putchar('!');
						++subSum2;
						break;
			default	 :	putchar(ch);
		}
	}
	
	printf("%d replacement(s) of . with !\n", subSum1);
 	printf("%d replacement(s) of ! with !!\n", subSum2);
	
	getch();
	return 0;
}