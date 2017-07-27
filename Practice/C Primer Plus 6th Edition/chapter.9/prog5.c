/*Напишите и протестируйте функцию по имени larger_of(), которая заменяет содержимое двух переменных double большим из их значений. 
Например, вызов larger_of(х, у) присвоит переменным х и у большее из их значений.*/
#include <stdio.h>
void program(double *, double *);
int main(void)
{
	double a, x;
	printf("This program replaces the contents of two variables\r\n");
	printf("enter a: ");
	scanf("%lf", &a);
	printf("enter b: ");
	scanf("%lf", &x);
	program(&a, &x);
	printf("After replace:\r\na = %2.f\r\nb = %.2f\r\n", a, x);
	return 0;
}
void program(double *a, double *x)
{
	if(a > x)
		{
			*x = *a;
		}
	else
		{
			*a = *x;
		}
}