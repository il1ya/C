/*Напишите функцию, которая возвращает индекс наибольшего значения в массиве значений типа double. 
Протестируйте эту функцию с помощью простой программы.*/
#include <stdio.h>
#define SIZE 3
int array1(const int[], int);
int main(void)
{
	int array[SIZE] = { 5, 9, 10 };
	printf("Array = %u", array1(array, SIZE));
	return 0;
}
int array1(const arr[], int size)
{
	int i;
	int array2 = 0;
	for(i = 0; i < size; i++)
	{
		if(arr[i] > arr[array2])
		{
			array2 = i;
		}
	}
	return array2;
}