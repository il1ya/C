/*3. Напишите функцию, которая возвращает наибольшее значение в массиве значений типа int. Протестируйте эту функцию с помощью простой программы.*/
#include <stdio.h>
#define SIZE 5
int array1(int [], int);
int main(void)
{
	int array[SIZE] = { 1, 2, 8, 39, 20 };
	printf("array %d\r\n", array1(array, SIZE));
	return 0;
}
int array1(int array[], int size)
{
	int i;
	int array2 = 0;
	for(i = 0, array2 = array[0]; i < size; i++)
	{
		if(array[i] > array2)
		{
			array2 = array[i];
		}
	}
	return array2;
}