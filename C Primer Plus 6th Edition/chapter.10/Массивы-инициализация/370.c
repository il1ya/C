// А что, если вы забудете инициализировать массив? В листинге 10.2 показано, что произойдет.
// no_data.c -- неинициализированный массив
#include <stdio.h>
#define SIZE 4
int main(void)
{
	int no_data[SIZE]; // неинициализированный массив
	int i;
	// printf("%2s%14s\r\n"); почему-то у меня компилируется с ошибкой!
	for(i = 0; i < SIZE; i++)
		printf("%2d%14d\r\n", i, no_data[i]);
	return 0;
}