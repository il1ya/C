/*
Используя операторы if else, напишите программу, которая читает входные данные, пока не встретит символ #, заменяет каждую точку восклицательным знаком, 
изначально присутствующие восклицательные знаки — двумя восклицательными знаками и в конце сообщает о количестве произведенных замен.
*/
#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int subSum = 0;
	printf("Enter text to be analyzed (# to terminate):\r\n");
	while((ch = getchar()) != STOP)
	{
		if(ch == '.')
		{
			ch = '!';
			++subSum;
		}
		else if(ch == '!')
		{
			ch = '!' + '!';
			++subSum;
		}
	}
	printf("There were %d substitutions made.\r\n", subSum);
	return 0;
}