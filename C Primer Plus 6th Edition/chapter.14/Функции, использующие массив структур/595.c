/*Предположим, что имеется массив структур, который необходимо обработать с помощью функции. 
Имя массива — это синоним его адреса, так что его можно передавать функции. 
Вдобавок функция нуждается в доступе к шаблону структуры. Чтобы продемонстрировать, как это работает, в листинге 14.13 программа финансового анализа
расширена с целью обслуживания двух человек, поэтому в ней присутствует массив из двух структур funds.*/
// Листинг 14.13. Программа funds4.с

/*funds4.c -- передача функции массива структур*/

#include <stdio.h>

#define FUNDLEN 50
#define N 2

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
/*Имя массива jones является его адресом. 
В частности, это адрес первого элемента массива, которым представляет собой структуру jones[0].*/
	struct funds jones[N] = 
	{
		{
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
		},
			{
			"Honest Jack's Bank",
			3620.88,
			"Party Time Savings",
			3802.91
			}
	};

	printf("The Joneses have a total of $%.2f.\r\n", sum(jones, N));
/*Для доступа к последующим структурам массива можно применять запись с квадратными скобками. 
Обратите внимание, что вызов функции sum(&jones[0], N)
приведет к таким же результатам, как и в случае указания имени массива, поскольку jones и &jones[0] — это один и тот же адрес. 
Использование имени массива представляет собой просто косвенный способ передачи адреса структуры.*/
	return 0;
}
/*Из-за того, что функция sum() не должна изменять исходные данные, в ней применяется квалификатор const из ANSI С.*/
double sum(const struct funds money[], int n)
{
	double total;
	int i;

	for(i = 0, total = 0; i < n; i++)
/*Каждый элемент является структурой funds, поэтому для каждого из них можно применять операцию точки(.), чтобы обращаться к членам структуры.*/
		total += money[i].bankfund + money[i].savefund;
	return(total);
}