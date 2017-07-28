/*Напишите программу, которая инициализирует двумерный массив 3 х 5 значений типа double и использует функцию, основанную на массивах переменной длины, 
для копирования этого массива во второй двумерный массив. Кроме того, напишите функцию, основанную на массивах переменной длины, для отображения содержимого этих двух массивов. 
Вобщем случае обе функции должны быть способны обрабатывать произвольные массивы N х М. (Если вы не имеете доступа к компилятору, подлерживающему массивы переменной длины, примените
традиционный подход С с функциями, которые могут обрабатывать массивы N x 5).*/
#include <stdio.h>
#define SIZE1 3
#define SIZE2 5
void copy_variable_array(const unsigned int size1, const unsigned int size2, double target[size1][size2], const double array[size1][size2]);
void print(const unsigned int size1, const unsigned int size2, const double arr[size1][size2]);
int main(void)
{
	double array[SIZE1][SIZE2] = {
		{ 2.2, 3.2, 4.5, 5.5, 6.8 },
		{ 5.5, 7.8, 2.3, 5.6, 3.2 },
		{ 0.2, 2.2, 1.1, 2.3, 4.7 } };
		double target[SIZE1][SIZE2];
		copy_variable_array(SIZE1, SIZE2, target, array);
		print(SIZE1, SIZE2, target);
		return 0;
}
void copy_variable_array(const unsigned int size1, const unsigned int size2, double target[size1][size2], const double array[size1][size2])
{
	unsigned int i, j;
	for(i = 0; i < size1; i++)
	{
		for(j = 0; j < size2; j++)
		{
			target[i][j] = array[i][j];
		}
	}
}void print(const unsigned int size1, const unsigned int size2, const double arr[size1][size2])
{
	unsigned int i, j;
	for(i = 0; i < size1; i++)
	{
		for(j = 0; j < size2; j++)
		{
			printf("%.2f\r\n", arr[i][j]);
		}
		printf("\r\n");
	}
}