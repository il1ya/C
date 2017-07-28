/*Напишите программу, которая инициализирует массив значений типа double и затем копирует его содержимое в три других массива. 
(Все четыре массива должны быть объявлены в главной программе.) Для создания первой копии воспользуйтесь функцией, в которой применяется форма записи с массивами. 
Для создания второй копии используйте функцию, в которой применяется форма записи с указателями и инкрементирование указателей. 
Первые две функции должны принимать в качестве аргументов имя целевого массива, имя исходного массива и количество элементов, подлежащих копированию. 
Третья функция должна принимать в качестве аргументов имя целевого массива, имя исходного массива и указатель на элемент, следующий за последним элементом в исходном
массиве. С учетом приведенных ниже объявлений вызовы функций должны выглядеть так:
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double targetl[5];
double target2[5];
double target3[5];
copy_arr(targetl, source, 5);
copy_ptr(target2, source, 5);
copy_ptrs(target3, source, source + 5);*/

#include <stdio.h>
#define SIZE 5
void copy_arr(const double [], double [], const int);
void copy_ptr(const double *, double *, const int);
void copy_ptrs(const double [], const int);
int main(void)
{
	double source[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[SIZE];
	double target2[SIZE];

	copy_arr(source, target1, SIZE);
	copy_ptr(source, target2, SIZE);

	printf("Array 1\r\n");
	copy_ptrs(source, SIZE);
	printf("Array 2\r\n");
	copy_ptrs(target1, SIZE);
	printf("Array 3\r\n");
	copy_ptrs(target2, SIZE);

	return 0;
}

void copy_arr(const double source[], double target[], const int size)
{
	for(int i = 0; i < size; i++)
	{
		target[i] = source[i]; 
	}
}

void copy_ptr(const double *source, double *target, const int size)
{
	const double *ptr;
	for(ptr = source; ptr < source + size; ptr++, target++)
	{
		*target = *ptr;
	}
}

void copy_ptrs(const double arr[], const int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%.2f\t", arr[i]);
	}
	printf("\r\n");
}