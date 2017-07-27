// листинг 9.10. Модуль функций поддержки hotel.c
// hotel.c -- функции управления отелем
#include <stdio.h>
#include "hotel.h"
int menu(void)
{
	int code, status;
	printf("\r\n%s%s\r\n", STARS, STARS);
	printf("Enter the number of the desired hotel:\r\n"); // Введите число, соответствующее выбранному отелю:
	printf("1) Fairfield Arms 		2) Hotel Olympic\r\n");
	printf("3) Chertworthy Plaza 		4) The Stockton\r\n");
	printf("5) quit\r\n");
	printf("%s%s\r\n", STARS, STARS);
	while((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5))
	{
		if (status != 1)
			scanf("%*s"); // отбрасывание нецелочисленного ввода
		printf("Please enter an integer, such as 2.\r\n");
	}
	return code;
}
int getnights(void)
{
	int nights;
	printf("How many nights are needed? ");
	while(scanf("%d", &nights) != 1)
	{
		scanf("%*s"); // исключение нецелочисленного ввода
		printf("Please enter an integer, such as 2.\r\n"); // Введите целое число, такое как 2
	}
	return nights;
}
void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for(n = 1; n <= nights; n++, factor *= DISCOUNT)
		total += rate * factor;
	printf("The total cost will be $%0.2f.\r\n", total); // Общая стоимость составляет $
}