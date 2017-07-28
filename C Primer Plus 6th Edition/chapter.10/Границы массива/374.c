/* Рассмотрим программу из листинга 10.6. Она создает массив с четырьмя элементами, 
а затем беспечно использует значения индекса в диапазоне от -1 до 6.*/
// Листинг 10.6. Программа bounds.c
// bounds.c -- выход за границы массива
#include <stdio.h>
#define SIZE 4
int main(void)
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	// компилятор сохранил значение value1 непосредственно после массива, а значение value2 — прямо перед ним.
	int i;
	printf("\r\nvalue1 = %d, value2 = %d\r\n", value1, value2);
	for(i = -1; i <= SIZE; i++)
		arr[i] = 2 * i + 1;
	for(i = -1; i < 7; i++)
		printf("%2d %d\r\n", i, arr[i]);
	printf("value1 = %d, value2 = %d\r\n", value1, value2);
	printf("address arr[-1]: %p\r\n", &arr[-1]); // arr[-1] соответствует той же ячейке памяти, что и value2
	printf("address arr[4]: %p\r\n", &arr[4]); // arr[4] — той же ячейке памяти, что и value1.
	// Следовательно, применение индексов, выходящих за границы массива, приводит к тому, что программа изменяет значения других переменных.
	printf("address value1: %p\r\n", &value1);
	printf("address value2: %p\r\n", &value2);
	return 0;
}