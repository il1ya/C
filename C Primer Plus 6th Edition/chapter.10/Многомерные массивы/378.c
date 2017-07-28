// Листинг 10.7. Программа rain.c
/* rain.c -- находит суммарные данные по годам, средние значения за год и средние значения за месяц по данным об осадках за несколько лет*/
#include <stdio.h>
#define MONTHS 12 // количество месяцев в году
#define YEARAS 5 // количество лет, для которых доступны данные
int main(void)
{
	// инициализация данными об осадках за период с 2010 по 2014 гг.
	const float rain[YEARAS][MONTHS] = 
	{
	{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
	{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
	{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
	{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
	{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
	};
	int year, month;
	float subtot, total;
	printf(" YEARAS 	RAINFALL (inches)\r\n"); // ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)
	// обработка каждого года
	for(year = 0, total = 0; year < YEARAS; year++)
	{ // для каждого года суммировать количество осадков за каждый месяц
		// обработка каждого мясяца
		for(month = 0, subtot = 0; month < MONTHS; month++)
			subtot += rain[year][month];
		printf("%5d %15.1f\r\n", 2010 + year, subtot);
		total += subtot; // общая сумма для всех лет
	}
	printf("\r\nThe yearly average is is %.1f inches.\r\n", total / YEARAS); // Среднегодовое количество осадков состовляет
	printf("MONTHLY AVERAGES: \r\n\r\n"); // СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\r\n");
	/*Вторая часть программы имеет ту же самую структуру, но теперь year изменяется во внутреннем цикле, а month — во внешнем.*/
	for(month = 0; month < MONTHS; month++)
		// для каждого месяца суммировать количество осадков на протяжении годов
		{
			for(year = 0, subtot = 0; year < YEARAS; year++)
				subtot += rain[year][month];
			printf("%4.1f", subtot / YEARAS);
		}
		printf("\r\n");
		return 0;
}