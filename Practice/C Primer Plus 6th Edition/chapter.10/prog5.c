/*Напишите функцию, которая возвращает разность между наибольшим и наименьшим элементами в массиве значений типа double. 
Протестируйте эту функцию с помощью простой программы.*/
#include <stdio.h>
#define SIZE 5
double array1(double [], int);
int main(void)
{
	double array[SIZE] = { 2.2, 2.2, 5.5, 5.5, 5.5 };
	printf("Array = %.2f\r\n", array1(array, SIZE));
	return 0;
}
double array1(double arr[], int size)
{
	unsigned int i = 0, max = 0, min = 0;
	for(i = 0; i < size; i++)
	{
		if(arr[i] > arr[max])
		{
			max = i;
		}
		else if(arr[i] < arr[min])
		{
			min = i;
		}
	}
	return arr[max] - arr[min];
}