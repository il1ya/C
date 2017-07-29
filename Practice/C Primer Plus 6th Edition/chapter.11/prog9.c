/*9. Напишите функцию, которая заменяет содержимое указанной строки этой же строкой, но с обратным порядком следования символов. 
Протестируйте функцию в завершенной программе, которая использует цикл для передачи входных значений созданной функции.*/
#include <stdio.h>
#include <string.h>
#define SIZE 81
void reverse(char *ptr);
int main(void)
{
	char string[SIZE];
	for(; puts("Enter a string:"),gets(string), *string != 'q';)
	{
		printf("Before: %s\r\n", string);
		reverse(string);
		puts("Reversing...");
		printf("After: %s\r\n", string);
	}
	puts("Bye!");
	return 0;
}
void reverse(char *ptr)
{
	char temp;
	int i, j;
	int len = strlen(ptr);
	for (i = 0; i < len / 2; i++)
	{
		temp = ptr[i];
		ptr[i] = ptr[len - 1 - i];
		ptr[len - 1 - i] = temp;
	}
}