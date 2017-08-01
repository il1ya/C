/*1. Переделайте задание из вопроса 5 таким образом, чтобы артуменг был представлен названием месяца, а не его номером. 
(Не забывайте о функции strcmp().)
Протестируйте готовую функцию в простой программе.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct month
{
	char name[21];
	char abbr[4];
	int days;
	int mnum;
};
int days(const struct month *p, char *select);

int main(void)
{
	int index = 0;
	int tot = 0;
	char temp[21];
	struct month year[12] =
{
	{ "January", "jan", 31, 1},
	{ "February", "feb", 28, 2},
	{ "March", "mar", 31, 3},
	{ "April", "apr", 30, 4},
	{ "May", "may", 31, 5},
	{ "June", "jun", 30, 6},
	{ "July", "jul", 31, 7},
	{ "August", "aug", 31, 8},
	{ "September", "sem", 30, 9},
	{ "October", "oct", 31, 10},
	{ "November", "nov", 30, 11},
	{ "December", "dec", 31, 12}
};
	puts("Please enter month name.");
	gets(temp);
	tot = days(year, temp);
	printf("Totoal days till %s is %d days.\r\n", temp, tot);

	return 0;
}

int days(const struct month *p, char *select)
{
	int count = 0;
	int sum = 0;
	for(int i = 0; i < 12; i++)
	{
		if(strcmp((p + i) -> name, select) == 0)
		{
			count = i;
			break;
		}
	}
	for(int j = 0; j < count; j++)
		sum +=(p + j) -> days;
	return sum;
}