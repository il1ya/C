/*
Напишите программу, которая запрашивает два числа с плавающей запятой и выводит значение их разности, деленной на их произведение. 
Программа должна обрабатывать пары вводимых чисел до тех пор, пока пользователь не введет нечисловое значение.
*/
#include <stdio.h>
int main (void)
{
	double n1, n2;
	double result;
	printf("Enter two floating-point numbers: ");
	while(scanf("%lf %lf", &n1, &n2) == 2)
	{
		result = (n1 - n2) / (n1 * n2);
		printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\r\n", n1, n2, n1, n2, result);
		printf("Enter two floating-point numbers (non-numeric value to quit): ");
	}
	return 0;
}