/*
значения не поменялись. Чтобы посмотреть, что именно пошло не так, давайте добавим в функцию interchange() несколько операторов вывода 
(листинг 9.14).
Листинг 9.14. Программа swap2.с
*/
/*swap2.c — исследование программы swapl.c */
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
	printf("Originally u = %d and v = %d.\r\n", u, v);
	temp = u;
	u = v;
	v = temp;
	printf("Originally u = %d and v = %d.\r\n", u, v);
}