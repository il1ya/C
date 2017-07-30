#include <stdio.h>
#include "illya.h"
static int mode;
static double distance;
static double fuel;
void set_mode(int n)
{
	if(n == METRIC || n == US)
		mode = n;
	else
	{
		if(n >= 1)
			mode = US;
		else
			mode = METRIC;
		printf("Invalib mode specified. Mode %d(%s) used.\r\n", mode, mode == 1?"US":"METRIC");
	}
}


void get_info(void) /*Функция get_info() запрашивает ввод данных согласно выбранному режиму и сохраняет ответы в переменных с областью видимости в пределах файла. */
{
	if(mode == 1)
	{
	puts("Enter distance traveled in kilometers: ");
	scanf("%lf", &distance);
	puts("Enter fuel consumed in liters: ");
	scanf("%lf", &fuel);
	}
	else
	{
	puts("Enter distance traveled in kilometers: ");
	scanf("%lf", &distance);
	puts("Enter fuel consumed in liters: ");
	scanf("%lf", &fuel);
	}
}

void show_info(void) /*Функция show_ info() вычисляет и отображает расход топлива на основе выбранного режима*/
{
	if(mode == 1)
	printf("Fuel consumption is %.2lf liters per gallon.\r\n", distance / fuel);
	else
	printf("Fuel consumption is %.2lf liters per kilometer.\r\n", fuel / distance);
}