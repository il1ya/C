/*В главе 6 была показана функция power() (листинг 6.20), которая возвращает результат возведения числа double в положительную целую степень.
Усовершенствуйте эту функцию, чтобы она корректно возводила числа в отрицательные степени. 
Кроме того, добавьте в функцию возможность оценки как О результата возведения О в любую степень кроме О и оценки как 1 результата возведения любого числа в степень О. 
(Функция должна сообщать, что результат возведения О в степень О не определен и что она использует значение 1.)
Примените цикл. Протестируйте функцию в какой-нибудь программе.*/
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
	int i = 0;
	if(n == 0)
	{
		return 0.0;
	}
	if(p == 0)
	{
		return 1.0;
	}
	i = (p > 0) ? p : (-p);
	while(--i != 0)
	{
		powe *= n;
	}
	return (p > 0) ? powe : ((double)1 / powe);
}