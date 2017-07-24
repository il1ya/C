// ch06ex07.c

/* Write a program that reads a single word into a character array & then prints the word backward. Hint: Use strlen() (Chapter 4) to compute the index of the last character in the array. */

#include <stdio.h>
#include <string.h>

int main(void)
{
	const int SIZE = 25;
	char i, word[SIZE];
	int wordLength = strlen(word);
	
	printf("Enter a single word: ");
	scanf("%s", word);
	
	for (i = wordLength; i >= 0; i--)
	{
		printf("%c", word[i]);
	}
	
	getch();
	return 0;
}