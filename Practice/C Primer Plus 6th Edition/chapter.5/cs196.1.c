/* Напишите программу, которая преобразует время в минутах в часы и минуты.
Для значения бО создайте символическую констану посредством #define или
const. Используйте цикл while, чтобы обеспечить пользователю возможность
повторного ввода значений и для прекращения цикла, если вводится значение
времени, меньшее или равное нулю. */
#include <stdio.h>
const int MIN = 60;
int main (void)
{
	float enter;
	float decision;
	char name[10];
	printf("\r\nGood afternoon!\r\n");
	printf("\r\nWhat is your name?\r\n");
	scanf("%s", name);
	printf("\r\nGood, %s. Please, enter your time in minutes \r\n", name);
	while (enter > 0)
	{
		scanf("%f", &enter);
		decision = enter / MIN;
		printf("\r\n%s your time h%1.2fm\r\nenter the next number or 0 to exit\r\n", name, decision);
	}
	return 0;
}