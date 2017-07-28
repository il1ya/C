/*Напишите функцию, которая изменяет порядок следования содержимого массива значений типа double на противоположный и протестируйте ее в простой программе.*/
#include <stdio.h>
#define SIZE 6
double array(double [], unsigned int);
int main(void)
{
	double arr[SIZE] = { 2.4, 2.7, 7.5, 7.2, 8.2, 3.4 };
	printf("This programm change the order of an array of double values content to the opposite");
	printf("Array = %.2f\r\n", array(arr, SIZE));
	return 0;
}
double array(double arr[], unsigned int size)
{
	
}