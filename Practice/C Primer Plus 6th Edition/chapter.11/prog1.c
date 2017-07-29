/*1. Разработайте и протестируйте функцию, которая извлекает из ввода следующие n символов (включая символы пробела, табуляции и новой строки), 
сохраняя результаты в массиве, адрес которого передается в качестве аргумента.*/
#include <stdio.h>
#define MAX_SIZE 68
void read_char(char [], const unsigned int);
int main(void)
{
	unsigned int n = 0;
	char array[MAX_SIZE];

	printf("This program following extracts from the input n characters\r\n" 
		"(including blanks, tabs, and newlines)\r\n");
	puts("Input the length of the string:");
	scanf("%u", &n);
	puts("Enter your string:");
	read_char(array, n);
	puts(array);
	return 0;
}
void read_char(char array[], const unsigned int n)
{
	unsigned int i = 0;
	while(getchar() != '\n');
		for(i = 0; i < n; i++)
		{
			array[i] = getchar();
		}
		array[n] = '\0';
}