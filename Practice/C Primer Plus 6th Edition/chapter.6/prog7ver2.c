// ch06ex07v2.c

// Write a version of ch06ex07 that uses strrev() from string.h instead of strlen().

#include <stdio.h>
#include <string.h>

int main(void)
{
	const int SIZE = 25;
	char word[SIZE];
	char *reverse;
	
	printf("Enter a single word: ");
	scanf("%s", word);
	
	reverse = strrev(word);
	
	printf("%s", reverse);

	getch();
	return 0;
}