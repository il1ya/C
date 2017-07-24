/*
Напишите программу, которая создает массив из 26 элементов и помещает в него 26 строчных букв английского алфавита. 
Также предусмотрите вывод содержимого этого массива.
*/ 
#include <stdio.h>
int main (void)
{
	const int ROWS = 1;
	const int CHARS = 26;
	int row;
	char ch;
	for (row = 0; row < ROWS; row++)
	{
		for (ch = ('A' + row); ch < ('A' + CHARS); ch++)
			printf("%c", ch);
		printf("\r\n");
	}
	return 0;
}