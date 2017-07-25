/*
Что выведет следующая программа при указанном вводе?
q
с
h
b
*/
#include <stdio.h>
int main(void)
{
	char ch;
	while ((ch = getchar()) != '#')
	{
		if(ch == '\n')
			continue;
		printf("step 1\r\n");
		if (ch == 'c')
			continue;
		else if(ch == 'b')
			break;
		else if(ch == 'h')
			goto laststep;
		printf("step 2\r\n");
		laststep: printf("step 3\r\n");
	}
	printf("End\r\n");
	return 0;
}