// Листинг 10.17 Программа array2d.c
// array2d.c -- функции для двумерных массивов
#include <stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sun_cols(int [][COLS], int ); // имена можно опустить
int sum2d(int (*ar)[COLS], int rows); // другой синтаксис
int main(void)
{
	int junk[ROWS][COLS] = { 
		{ 2, 4, 6, 8 }, 
		{ 3, 5, 7, 9 }, 
		{ 12, 10, 8, 6 } 
	};
	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\r\n", sum2d(junk, ROWS)); // сумма всех элементов
	return 0;
}
void sum_rows(int ar[][COLS], int rows)
{
	int tot;
	for(int r = 0; r < rows; r++)
	{
		tot = 0;
		for(int c = 0; c < COLS; c++)
			tot += ar[r][c];
		printf("row %d: sum = %d\r\n", r, tot); // строка. сумма
	}
}
void sum_cols(int ar[][], int rows)
{
	int tot;
	for(int c = 0; c < COLS; c++)
	{
		tot = 0;
		for(int r = 0; r < ROWS; r++)
			tot += ar[r][c];
		printf("col %d: sum = %d\r\n", c, tot); // столбец. сумма
	}
}
int sum2d(int ar[][COLS], int rows)
{
	int tot = 0;
	for(int r = 0; r < rows; r++)
		for(int c = 0; c < COLS; c++)
			tot += ar[r][c];
		return tot;
}