/* Выводит размеры типов */
#include <stdio.h>
int main (void)
{
	/* В стандарте с99 для размеров предусмотрен спецификатор %zd */
	printf("type int has a size %zd byte.\r\n", sizeof(int));
	printf("type char has a size %zd byte.\r\n", sizeof(char));
	printf("type long has a size %zd byte.\r\n", sizeof(long));
	printf("type long long has a size %zd byte. \r\n", sizeof(long long));
	printf("type double has a size %zd byte.\r\n", sizeof(double));
	printf("type long double has a size %zd byte.\r\n", sizeof(long double));
	return 0;
}