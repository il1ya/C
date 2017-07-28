// day_mon1.c -- выводит количество дней в каждом месяце
#include <stdio.h>
#define MONTHS 12
int main(void)
{
	int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for(int index = 0; index < MONTHS; index++)
		printf("Months %d It has %d day (days).\r\n", index + 1, days[index]);
	return 0;
}