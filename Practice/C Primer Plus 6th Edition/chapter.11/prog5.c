/*5. Разработайте и протестируйте функцию, которая ищет в переданной в первом параметре строке первое вхождение символа, заданного во втором параметре.
Функция должна возвратить указатель на этот символ, если он найден, и ноль в противном случае. 
(Поведение этой функции дублирует работу библиотечной функции strchr().) Протестируйте функцию в завершенной программе, которая
использует цикл для передачи входных значений созданной функции.*/
#include <stdio.h>
#include <stdbool.h>
#include <stdio_ext.h>
bool is_within(const char, const char *);
int main(void)
{
	const unsigned int SIZE = 128;
	char array[SIZE];
	char ch;
	while(true)
	{
		puts("Input a string:");
		_fpurge(stdin);
		fgets(array, SIZE, stdin);
		puts("Input a char:");
		_fpurge(stdin);
		ch = getchar();
		if(is_within(ch, array))
		{
			puts("In!");
		}
		else
		{
			puts("Out!");
		}
	}
}
bool is_within(const char ch, const char *array)
{
	const char *arr = array;
	while(*arr != '\0')
	{
		if(*arr == ch)
		{
			return true;
		}
		arr++;
	}
	return false;
}