// ch06ex01.c

/* Write a program that creates an array with 26 elements & stores the 26 lowercase letters in it. Also have it show the array contents. */

#include <stdio.h>

int main(void)
{
	const int SIZE = 26;	// There are 26 lowercase letters in the alphabet.
	char letters[SIZE];		// Defines an array & reserves space for 26 bytes/chars.
	int i;					// Defines an int that represents the array's subscripts.
	
	for (i = 0; i <= SIZE; i++)
	{
		letters[i] = 'a' + i;
	}
	
	for (i = 0; i <= SIZE; i++)
	{
		printf("%2c", letters[i]);
	}
	
	getch();	// This is used to prevent the console window from closing.	
	return 0;
}