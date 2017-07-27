/*Среднее гармоническое значение двух чисел получается путем инвертирования этих чисел, вычисления среднего значения инверсий и получения инверсии результата.
Напишите функцию, которая принимает два аргумента double и возвращает среднее гармоническое значение этих двух чисел.*/
#include <stdio.h>
double program(double, double);
int main(void)
{
	double a, x;
	printf("This program returns the the harmonic mean value.\r\n");
	printf("enter one double number: ");
	scanf("%lf", &a);
	printf("enter two double number: ");
	scanf("%lf", &x);
	printf("Harmonic mean %.2f\r\n", program(a, x));
	return 0;
}
double program(double a, double x)
{
	return 2 / (1 / a + 1 / x);
}
