#include <stdio.h> // несогласованные преобразования с плавающей запятой
int main (void)
{
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;
	printf("%.le %.le %.le %.le\r\n", n1, n2, n3, n4);
	printf("%ld %ld\r\n", n3, n4);
	printf("%ld %ld %ld %ld\r\n", n1, n2, n3, n4);
	return 0;
}