/*Для компиляторов, которые разрешают передавать структуры в качестве аргументов, последний пример можно переписать так, как показано в листинге 14.7.*/
// Листинг 14.7. Программа funds3.c
/*funds3.c -- передача структуры*/

#include <stdio.h>

#define FUNDLEN 50

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
/*Мы заменили указатель на struct funds по имени money переменной типа struct funds с именем moolah.*/
double sum(struct funds moolah); /*аругмент является структурой*/

int main(void)
{
		struct funds stan = 
		{
			"Garlic-Melon Bank",
			4032.27,
			"Lucky's Savings and Loan",
			8543.94
		};
/*при вызове sum() создается автоматическая переменная moolah, согласованная с шаблоном funds. 
Затем члены этой структуры инициализируются копиями значений соответствующих членов структуры stan. 
По этой причине вычисления производятся с участием копии исходной структуры, тогда как
в предыдущей программе (в которой использовался указатель) задействована сама исходная структура.*/
		printf("Stan has a total of $%.2f.\r\n", sum(stan));

		return 0;
}

double sum(struct funds moolah)
{
/*Так как moolah является структурой, в программе применяется moolah.bankfund, а не moolah -> bankfund. 
С другой стороны, в листинге 14.6 используется money -> bankfund, потому что money — указатель, а не структура.*/
	return(moolah.bankfund + moolah.savefund);
}