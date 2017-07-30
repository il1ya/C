/*Напишите программу, которая генерирует список из 100 случайных чисел в диапазоне от 1 до 10, отсортированный по убыванию. 
(Можете приспособить к типу int алгоритм сортировки из главы 11, только в этом случае сортируйте сами числа.)*/
#include <stdio.h>
#include <stdlib.h>
void sort(int *p);
int main(void)
{
	int num[100];
	for(int i = 0; i < 100; i++)
		num[i] = rand() % 10 + 1;

	sort(num);
	for(int i = 0; i < 100; i++)
	{
		if(i % 10 == 0 && i != 0)
			printf("%d\r\n", num[i]);
		else
			printf("%d", num[i]);
	}
	return 0;
}
void sort(int *p)
{
	int temp;
	int i, j;
	for(i = 0; i < 99; i++)
		for(j = i + 1; j < 100; j++)
			if(p[i] < p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
}