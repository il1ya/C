// Программа swap1.c
// swap1.c -- первая попытка создания функции обмена значениями
#include <stdio.h>
void interchange(int u, int v); // объявление функции
int main(void)
{
	int x = 5, y = 10;
	printf("Originally x = %d and y = %d.\r\n", x, y); // первоначально
	interchange(x, y);
	printf("Now x = %d and y = %d.\r\n", x, y); // теперь
	return 0;
}
void interchange(int u, int v) // определение функции
{
	int temp;
	temp = u;
	u = v;
	v = temp;
}