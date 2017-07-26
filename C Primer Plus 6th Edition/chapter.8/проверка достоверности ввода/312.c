/*
В листинге checking.с эти две функции применяются для предоставления целых чисел арифметической функции, которая вычисляет сумму квадратов всех целых чисел 
в указанном диапазоне. Программа ограничивает верхние и нижние пределы диапазона значениями 1000 и -1000, соответственно.
*/ 
// checking.c -- проверка допустимости ввода
#include <stdio.h>
#include <stdbool.h>
// проверка, является ли ввод целочисленным
long get_long(void);

// проверка, допустимы ли границы диапазона
bool bad_limits(long begin, long end, long low, long high);

// вычисление суммы квадратов целых чисел от a до b
double sum_squares(long a, long b);

//управляет потоком, делегируя задачи другим функциям.
int main(void)
{
	const long MIN = -10000000L; // нижний предел диапазона
	const long MAX = +10000000L; // верхний предел диапазона
	long start; // начало диапазона
	long stop; // конец диапазона
	double answer;
	printf("This program computes the sum of the squares of " // эта программа вычисляет сумму квадратов
		"integers in a range.\r\nThe lower bound should not " // целых чисел в заданном диапозоне. Нижняя граница не должна
		"be less than -10000000 and\r\nthe upper bound " // быть меньше -10000000, а верхняя не должна быть
		"should not be more than +10000000.\r\nEnter the " // больше +10000000. введите значения
		"limits (enter 0 for both limits to quit):\r\n" // пределов (для завершения введите 0 для обоих пределов)
		"lower limit: "); // нижний предел
	start = get_long();
	printf("upper limits: "); // верхний предел
	stop = get_long();
	while (start != 0 || stop != 0)
	{
		if(bad_limits(start, stop, MIN, MAX))
			printf("Please try again.\r\n"); // повторите попытку
		else
		{
			answer = sum_squares(start, stop);
			printf("The sum of the squares of the integers "); // сумма квадратов целых чисел
			printf("from %ld to %ld is %g\r\n", start, stop, answer);
		}
		printf("Enter the limits (enter 0 for both limits to quit:\r\n"); // введите значения пределов(для завершения введите 0 для обоих пределов)
		printf("lower limit: "); // нижний предел
		start = get_long();
		printf("upper limitL: "); // верхний предел
		stop = get_long();
	}
	printf("Done.\r\n"); // программа завершена
	return 0;
}
long get_long(void)
{
	long input;
	char ch;
	while(scanf("%ld", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch); // отбросить неправильный ввод
		printf(" is not an integer.\r\nPlease enter an integer value, such as 25, -178 or 3: "); // не является целочисленным. Введите целое число, такое как 25, -178 или 3
	}
	return input;
}
double sum_squares(long a, long b) // Вычислительное ядро
{
	double total = 0;
	long i;
	for (i = a; i <= b; i++)
		total += (double)i * (double)i;
	return total;
}
bool bad_limits(long begin, long end, long low, long high)
{
	bool not_good = false;
	if(begin > end)
	{
		printf("%ld isn't smaller than %ld.\r\n", begin, end); // не меньше чем 
		not_good = true;
	}
	if(begin < low || end < low)
	{
		printf("Values must be %ld or greater.\r\n", low); // значения должны быть равны или больше
		not_good = true;
	}
	if(begin > high || end > high)
	{
		printf("Values must be %ld or less.\r\n", high); // значения должны быть равны или меньше
		not_good = true;
	}
	return not_good;
}
