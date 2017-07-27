/*Еще раз выполните упражнение 8, но на этот раз используйте рекурсивную функцию.*/
#include <stdio.h>
double power(double, int); // прототип ANSI
int main (void)
{
	double x;
	int a;
	printf("This program Enter returns the result of raising the number to double in negative powers.\r\n");
	printf("Enter number one(double): ");
	scanf("%lf", &x);
	printf("Enter number two(int): ");
	scanf("%d", &a);
	printf("%.3g to the power %d is %.5g\r\n", x, a, power(x, a));
	return 0;
}
double power (double n, int p) // определение функции
{
	double powe = n;
	if(n == 0)
	{
		return 0.0;
	}
	if(p == 0)
	{
		return 1.0;
	}
	if (p > 0)
	{
		return n* power(n, p - 1);
	}
	else
	{
		return (double)1 / n * power(n, p + 1);
	}
}