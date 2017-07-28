/*Воспользуйтесь одной из функций копирования из упражнения 2 для копирования элементов с 3-го по 5-й семиэлементного массива в массив, состоящий из трех элементов. 
Саму функцию изменять не нужно; просто подберите правильные фактические аргументы. 
(Фактическими аргументами не обязательно должны быть имя массива и его размер. Ими только должны быть адрес элементамассива и количество обрабатываемых элементов.)*/
#include <stdio.h>
#define SIZE1 5
#define SIZE2 6
void copy_array(double [], const double [], const unsigned int);
void print(const double [], const unsigned int);
int main(void)
{
	double array[SIZE1] = { 2.2, 3.3, 4.4, 5.5, 6.6 };
	double array1[SIZE2];
	copy_array(array, &array1[2], SIZE2);
	print(array1, SIZE2);
	printf("\r\n");
	return 0;
}
void copy_array(double target[], const double source[], const unsigned int size)
{
	unsigned int i;
	for(i = 0; i < size; i++)
	{
		target[i] = source[i];
	}
}
void print(const double arr[], const unsigned int size)
{
	unsigned int i;
	for(i = 0; i < size; i++)
	{
		printf("%8.2f\r\n", arr[i]);
	}
}