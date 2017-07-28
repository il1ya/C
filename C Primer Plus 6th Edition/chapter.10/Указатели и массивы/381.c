// Листинг 10.8. Программа pnt_add.c
// pnt_add.c -- сложение указателей
#include <stdio.h>
#define SIZE 4
int main(void)
{
	short dates[SIZE];
	short *pti;
	double bills[SIZE];
	double *ptf;
	pti = dates; // Присваивание указателю адреса массива
	ptf = bills;
	printf("%23s %10s\r\n", "short", "double");
	for(short index = 0; index < SIZE; index++)
		printf("Indices + %d: %10p %10p\r\n", index, pti + index, ptf + index); // указатели
	return 0;
}