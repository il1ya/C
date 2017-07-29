/*Напишите функцию, которая принимает строку в качестве аргумента и удаляет из нее все пробелы. 
Протестируйте эту функцию в программе, которая использует цикл для чтения строк до тех пор, пока не будет введена пустая строка.
Программа должна применять эту функцию к каждой входной строке и отображать результат.*/
#include <stdio.h>
#include <string.h>
#define SIZE 81
void dropspace(char *ptr);
int main(void)
{
	char string[SIZE];
	for(; puts("Enter a string:"), gets(string), *string != ' ';)
	{
		printf("Before: %s\r\n", string);
		dropspace(string);
		puts("droping...");
		printf("After: %s\r\n", string);
	}
	puts("Bye!");
	return 0;
}
void dropspace(char *ptr)
{
	char temp[SIZE];
	int len = strlen(ptr);
	int i;
	for(i = 0; i < len; i++)
	{
		if(ptr[i] != ' ')
			temp[i] = ptr[i];
		else
			temp[i] = '\b'; // it's kind of cheating but whatever
	}
	for(; i > 0; --i)
		ptr[i] = temp[i];
}