/*Завершите программу, предоставив определения функций make_array() и show_array(). Функця make_array() принимает два аргумента. 
Первый аргумент- это количество элементов в массиве значений int, а второй аргумент — значение, которое должно быть присвоено каждому элеменгу массива. 
Эта функция использует malloc() для создания массива подходящего размера, присваивает каждому элеменгу заданное значение и возвращает указатель на массив. 
Функция show_array() отображает содержимое массива по восемь элементов в строке.*/
#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int *pa;
	int size;
	int value;

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	while(size > 0)
	{
		printf("Enter the initialization value: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if(pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (1 to quit): ");
		scanf("%d", &size);
	}
	printf("Done.\r\n");
	return 0;
}

int *make_array(int elem, int val)
{
	int *ptr;
	ptr = (int *)malloc(elem *sizeof(int));
	for(int i = 0; i < elem; i++)
		ptr[i] = val;
	return ptr;
}

void show_array(const int ar[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(i % 7 == 0 && i != 0)
			printf("%3d\r\n", ar[i]);
		else
			printf("%3d", ar[i]);
	}
	printf("\r\n");
}