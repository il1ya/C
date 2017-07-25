/*
Напишите программу, которая читает входные данные до тех пор, пока не встретится символ #, а затем отображает количество прочитанных пробелов, 
количество символов новой строки и количество всех остальных символов.
*/
#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int i = 0;
	int b = 0;
	int c = 0;
	while((ch = getchar()) != STOP)
	{
		if(!isspace(ch))
			i++;
		else if(ch = '\n')
			b++;
		else
			c++;
	}
	printf("spaces: %d, lines: %d, others: %d\n", i, b, c);
	return 0;
}