/*
Модифицируйте упражнение 8 так, чтобы программа использовала функцию для возврата результатов вычислений.
*/
#include <stdio.h>
double illya(double, double);
int main (void)
{
	double n1, n2;
	double result;
	printf("Enter two floating-point numbers: ");
	while(scanf("%lf %lf", &n1, &n2) == 2)
	{
		result = illya(n1, n2);
		printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\r\n", n1, n2, n1, n2, result);
		printf("Enter two floating-point numbers (non-numeric value to quit): ");
	}
	return 0;
}
double illya(double a, double b)
{
	double d = (a - b) / (a * b);
	return d;
}