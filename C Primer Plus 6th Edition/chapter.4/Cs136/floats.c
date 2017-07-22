#include <stdio.h> // Некоторые комбинаций для типов с плавающей запятой
int main (void)
{
	const double RENT = 3852.99; // константа, объявленная посредством const
	printf("*%f*\r\n", RENT);
	printf("*%e*\r\n", RENT);
	printf("*%4.2f*\r\n", RENT);
	printf("*%3.1f*\r\n", RENT);
	printf("*%10.3f*\r\n", RENT);
	printf("*%10.3E*\r\n", RENT);
	printf("*%+4.2f*\r\n", RENT);
	printf("*%010.2f*\r\n", RENT);
	return 0;
}