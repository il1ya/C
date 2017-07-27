/*
Мы модифицировали код в листинге 9.4 аля применения прототипа функции. Результат представлен в листинге 9.5.
*/
// proto.c -- ипсользует прототипы функции
#include <stdio.h>
int imax(int, int); // прототип
int main(void)
{
	printf("The maximum of %d and %d is %d.\r\n", 3, 5, imax(3, 5));
	printf("The maximum of %d and %d is %d.\r\n", 3, 5, imax(3.0, 5.0));
	return 0;
}
int imax(int n, int m)
{
	return (n > m ? n : m);
}