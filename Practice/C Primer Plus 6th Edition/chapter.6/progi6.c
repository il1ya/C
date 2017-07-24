/*
Напишите программу для вывода таблицы, в каждой строке которой представлено целое число, его квадрат и его куб. 
Запросите у пользователя верхний и нижний пределы таблицы. Используйте цикл for.
*/
#include <stdio.h>
int main (void)
{
	int up, down, n1, n2, n3;
	printf("Enter down ");
	scanf("%d", &down);
	printf("Enter up ");
	scanf("%d", &up);
	for(n1 = down; n1 <= up; n1++)
	{
		n2 = n1 * n1;
		n3 = n2 * n1;
		printf("%d %d %d", n1, n2, n3);
	}
	return 0;
}