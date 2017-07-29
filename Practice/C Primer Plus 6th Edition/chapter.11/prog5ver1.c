/*5. Разработайте и протестируйте функцию, которая ищет в переданной в первом параметре строке первое вхождение символа, заданного во втором параметре.
Функция должна возвратить указатель на этот символ, если он найден, и ноль в противном случае. 
(Поведение этой функции дублирует работу библиотечной функции strchr().) Протестируйте функцию в завершенной программе, которая
использует цикл для передачи входных значений созданной функции.*/
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