/*Напишите и протестируйте функцию, которая принимает в качестве аргументов адреса трех переменных double и 
помещает наименьшее значение в первую переменную,
среднее значение — во вторую, 
а наибольшее значение — в третью.*/
#include <stdio.h>
double program(double *, double *, double *);
int main(void)
{
	double a, b, c;
	printf("This program places the smallest value in the first variable,\r\nthe average value of - in the second, and the largest value - the third.\r\n");
	printf("enter a: ");
	scanf("%lf", &a);
	printf("enter b: ");
	scanf("%lf", &b);
	printf("enter c: ");
	scanf("%lf", &c);
	program(&a, &b, &c);
	printf("After replace:\r\na = %2.f\r\nb = %.2f\r\nc = %.2f\r\n", a, b, c);
	return 0;
}
double program(double *a, double *b, double *c)
{
	if(a > b || b > c)
	{
		*c;
	}
	/*else
		*c = *b = *a;*/
/*	if(a > b)
		{
			*b = *a;
		}
	else
		{
			*a = *b;
		}
	if(b > c)
		{
		*c = *b;
		}
	else
		{
		*b = *c;
		}*/
}