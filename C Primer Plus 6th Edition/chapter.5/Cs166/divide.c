#include <stdio.h> // деление, каким мы его знаем
int main (void)
{
	printf("integer division: 5/4 equally %d\r\n", 5 / 4); // целочисленное деление: равно
	printf("integer division: 6/3 equally %d\r\n", 6 / 3);
	printf("integer division: 7/4 equally %d\r\n", 7 / 4);
	printf("The division of floating point: 7./4. equally %1.2f\r\n", 7. / 4.); // деление с плавающей запятой
	printf("mixed division: 7./4 equally %1.2f\r\n", 7. / 4); // смешанное деление
	return 0;
}
