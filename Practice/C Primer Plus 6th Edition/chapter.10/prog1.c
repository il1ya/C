/*1. Модифицируйте программу rain.с из листинга 10.7, чтобы она выполняла вычисления с использованием указателей вместо индексов. 
(Вам по-прежнему придется объявлять и инициализировать массив.)*/

#include <stdio.h>
#define MONTHS 12 // количество месяцев в году
#define YEARAS 5 // количество лет, для которых доступны данные
int main(void)
{
	// инициализация данными об осадках за период с 2010 по 2014 гг.
	const float rain[YEARAS][MONTHS] = {
	{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
	{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
	{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
	{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
	{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
	};

	float prog, prog1;
	const float (*year)[MONTHS];
	const float *month;
	int cnt = 0, i = 0;

	printf(" YEARAS 	RAINFALL (inches)\r\n"); // ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)
	for(year = rain, prog1 = 0; year < rain + YEARAS; year++)
	{
		for(month = *year, prog = 0; month < *year + MONTHS; month++)
		{
			prog += *month;
		}
		printf("%5d %15.1f\r\n", 2010 + cnt, prog);
		cnt++;
		prog1 += prog;
	}
	printf("\r\nThe yearly average is is %.1f inches.\r\n", prog1 / YEARAS); // Среднегодовое количество осадков состовляет
	printf("MONTHLY AVERAGES: \r\n\r\n"); // СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\r\n");
	for(i = 0; i < MONTHS; i++)
		{
			for(year = rain, prog = 0; year < rain + YEARAS; year++)
			{
				prog += *(*year + i);
			}
			printf("%4.1f", prog / YEARAS);
		}
		printf("\r\n");
		return 0;
}