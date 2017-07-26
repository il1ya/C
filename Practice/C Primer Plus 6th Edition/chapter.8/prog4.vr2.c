#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch, pch;
	float average = 0; 
	float letters = 0; 
	float words = 0;
	printf("Enter character\r\n");
	while((ch = getchar()) != EOF && ch != '#')
	{
		if(isalpha(ch))
		{
			letters++;
			pch = ch;
		}
		else if(isalpha(ch) && isspace(ch))
		{
			words++;
		}
	}
	average = letters / words;
	printf("The average number of letters per word is %.2f", average);
	return 0;
}