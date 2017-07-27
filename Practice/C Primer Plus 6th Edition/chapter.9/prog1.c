/*Напишите функцию по имени rnin(х, у), которая возвращает меньшее из двух значений double. Протестируйте эту функцию с помощью простого драйвера.*/
#include <stdio.h>
#define STOP '#'
double program(double, double);
int main(void)
{
	printf("This program returns the smaller of the two values double.\r\n");
	printf("enter the number for comparison:\r\n");
	double	enter1, enter2;
	while ((scanf("%lf %lf", &enter1, &enter2)) == 2)
	{
		printf("%.2f (q to quit)", program(enter1, enter2));
	}

	return 0;
}
double program(double x, double y)
{
	if(x < y)
		return x;
	else
		return y;
}