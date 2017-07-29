/*Функция strcat() (от string concatenation — конкатенация строк) в качестве аргументов принимает две строки. 
Копия второй строки присоединяется в конец первой строки, и такая объединенная версия становится новой первой строкой. 
Вторая строка не изменяется. Функция strcat() имеет тип char * (т.е. указатель на char). 
Она возвращает значение своего первого аргумента — адрес первого символа строки, в конец которой была добавлена вторая строка.
В листинге 11.18 демонстрируются возможности функции strcat(). 
В коде также применяется функция s_gets(), которая была определена в листинге 11.10; 
вспомните, что s_gets() использует fgets() для чтения строки, а затем удаляет из нее символ новой сроки, если он присутствует.*/
// Листинг 11.18. Программа str_cat.c
// str_cat.c -- объединяет две строки
#include <stdio.h>
#include <string.h> // объявление strcat()
#define SIZE 80
char *s_gets(char * st, int n);
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	puts("What is your favorite flower?");
	if(s_gets(flower, SIZE))
	{
		strcat(flower, addon);
		puts(flower);
		puts(addon);
	}
	else 
		puts("End of file encountered!");
	puts("bye");
	return 0;
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] == '\0';
		else // требуется наличие words[i] == '\0'
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
/*Функция strcat() не проверяет, умещается ли вторая строка в первый массив.
Если вы не выделите достаточного пространства для первого массива, то столкнетесь с проблемой переполнения соседних ячеек памяти избыточными символами.*/