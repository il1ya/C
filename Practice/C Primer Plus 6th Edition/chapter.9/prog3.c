/*Напишите функцию, которая принимает три аргумента: символ и два целых числа.
Символ предназначен для вывода. Первое целое значение задает количество указанных символов в строке, 
а второе целое число устанавливает количество таких строк. Напишите программу, в которой используется эта функция.*/
#include <stdio.h>
void program(char, int, int);
int main(void)
{
	char ch;
	int x, y;
	printf("Enter character: ");
	ch = getchar();
	printf("Enter one integers: ");
	scanf("%d", &x);
	printf("Enter two integers: ");
	scanf("%d", &y);
	program(ch, x, y);
	printf("\r\n");
	return 0;
}
void program(char ch, int x, int y)
{
	int i = 0;
	while(x-- != 0)
	{
		for(i = 0; i < x; i++)
		{
			putchar(ch);
		}
		putchar('\n');
	}
}