#include <stdio.h>
#include <float.h> // Пределы для чисел с плавающей запятой
#include <limits.h> // Пределы для целых чисел
int main (void)
{
	printf("Some limits numbers for this system\r\n"); // Некоторые пределы чисел для данной системы
	printf("The largest value of type int: %d\r\n", INT_MAX); // Наибольшое значение типа int
	printf("The smallest value of type long long: %lld\r\n", LLONG_MIN); // Наименьшее значение типа long long
	printf("In this system one = %d byte\r\n", CHAR_BIT); // В данной системе один байт char
	printf("The largest value of type double: %e\r\n", DBL_MAX); // Наибольшее значения типа double
	printf("The smallest normalized value type float: %e\r\n", FLT_MIN); // Наименьше нармализованное значение типа float
	printf("The exact value of type float = %d sign\r\n", FLT_DIG); // Точное значение типа float
	printf("The difference between the value and the minimum value of 1.00 float, which is greater than 1.00 = %e", FLT_EPSILON); /*
	Разница между значением 1.00 и минимальным значением float, которое больше 1.00 */
	return 0;

}