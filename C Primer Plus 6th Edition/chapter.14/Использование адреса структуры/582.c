/*Мы будем решать ту же задачу, что и ранее, но на этот раз в качестве аргумента применим адрес структуры. 
Поскольку функция будет работать со структурой funds, она также должна использовать объявление funds. Код программы приведен в листинге 14.6.*/

// Листинг 14.6. Программа funds2.c
/*funds2.c -- передача указателя на структуру*/
#include <stdio.h>

#define FUNDLEN 50

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds *); /*аргумент является указателем*/

int main(void)
{
	struct funds stan = 
	{
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
/*Передача адреса &stan функции приводит к тому, что теперь указатель money указывает на структуру stan.*/
	printf("Stan has a total of $%.2f.\r\n", sum(&stan)); // Общая сумма на счетах у Стэна составляет
	return 0;
}
/*Функция sum() принимает указатель(money) на структуру funds в своем единственном аргументе.*/
double sum(const struct funds *money)
/*Поскольку функция не изменяет значение, на которое ссылается указатель, money объявляется как указатель на const.*/
{
/*Затем с помощью операции -> мы получаем значения stan.bankfund и stan.savefund.*/
	return(money -> bankfund + money -> savefund);
}