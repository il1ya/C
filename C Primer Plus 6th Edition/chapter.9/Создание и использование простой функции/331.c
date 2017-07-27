// lethead2.c
#include <stdio.h>
#include <string.h> // для strlen()
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '
// определение функции.
void show_n_char(char ch, int num); // функция принимает 2 аргумента с именами ch тип char и num тип int называются формальными параментрами
// ch и num присваиваются с использованием фактических аргументов в вызове функции.
// Несмотря на то что функция show_n_char() принимает значения из main(), она ничего не возвращает, поэтому show_nchar() имееет тип void.
int main(void)
{
	int spaces;
	show_n_char('*', WIDTH); // использование констант в качестве аргументов
	putchar('\n');
	// фактическими аргументами являются SPACE и 12.
	show_n_char(SPACE, 12); // использование констант в качестве аргументов
	printf("%s\r\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;
									// позволить программе вычислить сколько пробелов нужно вывести.
	show_n_char(SPACE, spaces); // использование переменной в качестве аргумента
	printf("%s\r\n", ADDRESS);
	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
								// использование выражения в качестве аргумента
	printf("%s\r\n", PLACE);
	show_n_char('*', WIDTH);
	putchar('\n');
	return 0;
}
// определение функции show_n char()
void show_n_char(char ch, int num)
{
	int count;
	for (count = 1; count <= num; count++)
		putchar(ch);
}