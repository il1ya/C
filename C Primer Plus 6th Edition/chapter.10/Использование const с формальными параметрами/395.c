/*В программе, показанной в листинге 10.14, одна функция отображает массив, а другая умножает каждый элемент массива на заданное значение. 
Поскольку первая функция не должна изменять массив, в ней используется const. Из-за того, что вторая функция намерена модифицировать массив, ключевое слово const в ней отсутствует.*/
// Листинг 10.14. Программа arf.c
// arf.c -- функции, манипулирующие массивами
#include <stdio.h>
#define SIZE 5
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);
int main(void)
{
	double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	printf("The original dip array:\r\n"); // Исходный массив
	show_array(dip, SIZE);
	mult_array(dip, SIZE, 2.5);
	printf("The dip array after calling mult_array():\r\n"); // Массив dip после вызова функции mult_array()
	show_array(dip, SIZE);
	return 0;
}
 /*выводит содержимое массива*/
void show_array(const double ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%8.3f", ar[i]);
	putchar('\n');
}
/*умножает каждый элемент массива на один и тот же множитель*/
void mult_array(double ar[], int n, double mult)
{
	int i;
	for(i = 0; i < n; i++)
		ar[i] *= mult;
}