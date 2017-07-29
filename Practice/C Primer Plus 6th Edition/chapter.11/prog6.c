/*6. Напишите функцию по имени is_within(), которая в качестве двух своих параметров принимает символ и указатель на строку. 
Функция должна возвращать ненулевое значение, если заданный символ содержится в строке, и ноль в противном случае. 
Протестируйте функцию в завершенной программе, которая использует цикл для передачи входных значений созданной функции.*/
#include <stdio.h>
#include <string.h>
#define SIZE 81
char *is_within(char *ptr, char c);
int main(void)
{
	char string[SIZE];
	char *ptr;
	char c;
	while(1)
	{
		puts("Please enter a string shorter than 80 characters.");
		gets(string);
		puts("Please enter a character to be find.(enter 'q' to quit)");
		if((c = getchar()) == 'q')
			break;
		getchar();
		ptr = is_within(string, c);
		if(ptr)
			printf("%c is within the string!\r\n", c);
		else
			puts("Bye!");
		return 0;
	}
}
char *is_within(char *ptr, char c)
{
	for(; *ptr != c; ptr++)
		if(*ptr == '\0') return NULL;
	return ptr;
}