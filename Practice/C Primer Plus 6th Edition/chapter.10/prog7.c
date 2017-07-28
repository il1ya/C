/*Напишите программу, которая инициализирует двумерный массив значений типа double и использует одну из 
функций копирования из упражнения 2 для его копирования во второй двумерный массив. 
(Поскольку двумерный массив -это массив массивов, функция для копирования одномерных массивов может применятся с каждым подмассивом.)*/
#include <stdio.h>
#define SIZE 5

void copy_ptr(const unsigned int size, const unsigned int size2, double arr[size2][size], const double arr1[size2][size]);

void copy_ptrs(const unsigned int size, const unsigned int size2, const double arr[size][size2]);

void copy_arr(double target[], const double source[], const int size);

int main(void)
{
	const unsigned int SIZE2 = 3;

	const double arr[SIZE2][SIZE] = {
		{ 2.4, 4.6, 6.3, 6.2, 8.6 },
		{ 3.4, 5.6, 3.0, 9.2, 7.6 },
		{ 6.4, 8.8, 6.6, 9.9, 4.3 } };
	double arr[SIZE2][SIZE];
	copy_ptr(SIZE2, SIZE, arr, arr1);
	copy_ptrs(SIZE2, SIZE, arr);
	return 0;
}

void copy_ptr(const unsigned int size, const unsigned in size2, double arr[size2][size], const double arr1[size2][size])
{
	unsigned int i = 0;
	for(i = 0; i < row; i++)
	{
		copy_arr(arr[i], arr1[i], size2);
	}
}

void copy_ptrs(const unsigned int size, const unsigned int size2, const double arr[size][size2])
{
	unsigned int i;
	unsigned int j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size2; j++)
		{
			printf("%.2f\t", arr[i][j]);
		}
	{
	printf("\r\n");
}

void copy_arr(double target[], const double source[], const int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		target[i] = source[i]; 
	}
}
