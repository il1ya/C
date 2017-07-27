/*
В листинге 9.12 эта операция применяется, чтобы посмотреть, где хранятся переменные, которые имеют одно и то же имя, но используются в разных функциях.
// Листинг 9.12. Программа loccheck.c
*/
// loccheck.c -- проверка для выяснения, где хранятся переменные
#include <stdio.h>
void mikado(int); // объявление функции
int main(void)
{
	int pooh = 2, bah = 5; // локальные для main()
	printf("In main(), pooh = %d and &pooh = %p\r\n", pooh, &pooh);
	printf("In main(), bah = %d and &bah = %p\r\n", bah, &bah);
	mikado(pooh);
	return 0;
}
void mikado(int bah) // определение функции
{
	int pooh = 10; // локальная для mikado()
	printf("In mikado(), pooh = %d and &pooh = %p\r\n", pooh, &pooh);
	printf("In mikado(), bah = %d and &bah = %p\r\n", bah, &bah);
}