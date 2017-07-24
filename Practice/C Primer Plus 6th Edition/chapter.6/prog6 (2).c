// ch06ex06.c

/* Write a program that prints a table with each line giving an integer, its square, & its cube. Ask the user to input the lower & upper limits for the table. Use a for loop. */

#include <stdio.h>

int main(void)
{
	int cube, index, lower, square, upper;
	
	printf("Enter the lower integer limit for the table: ");
	scanf("%d", &lower);
	printf("Enter the upper integer limit for the table: ");
	scanf("%d", &upper);
	
	for (index = lower; index <= upper; index++) {
		square = index * index;
		cube = index * square;
		printf("%5d %5d %5d\n", index, square, cube);
	}
	
	getch();	// This is used to prevent the console window from closing on some systems.
	return 0;
}