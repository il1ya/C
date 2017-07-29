/*Напишите программу реализации степенной зависимости, которая работает на основе командной строки. 
Первым аргументом командной строки должно быть число типа double, возводимое в определенную степень, а вторым аргументом - целочисленный показатель степени.*/
#include <stdio.h>
#include <math.h>
#define SIZE 20
int main(int argc, char *argv[])
{
	double base, exp, res;
	base = strtod(argv[1]);
	exp = strtod(argv[2]);
	res = pow(base, exp);
	printf("%.1lf ^ %.11f = %.11f\r\n", base, exp, res);
	return 0;
}