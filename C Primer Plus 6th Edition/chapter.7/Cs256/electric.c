// подсчитывает сумму для счета за электроэнергию
#include <stdio.h>
#define RATE1 0.13230 // тариф за первые 360 кВт/ч
#define RATE2 0.15040 // тариф за следующие 108 кВт/ч
#define RATE3 0.30025 // тариф за следующие 252 кВт/ч
#define RATE4 0.34025 // тариф, когда расход превышает 720 кВт/ч
#define BREAK1 360.0 // первая точка разрыва тарифов
#define BREAK2 468.0 // вторая точка разрыва тарифов
#define BREAK3 720.0 // третья точка разрыва тарифов
#define BASE1 (RATE1 * BREAK1) // стоимость 360 кВт/ч
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1))) // стоимость 468 кВт/ч
#define BASE3 (BASE1 + BASE2 + (RATE3 * (BREAK3 - BREAK2))) // стоимость 720 кВт/ч
int main(void)
{
	double kwh; // израсходованные киловатт-часы
	double bill; // сумма к оплате
	printf("Please enter the kwh esed.\r\n"); // Введите обьем израсходованной электроэнергии в кВт/ч
	scanf("%lf", &kwh); // %lf для типа double
	if (kwh <= BREAK1)
		bill = RATE1 * kwh;
	else if (kwh <= BREAK2) // количество кВт/ч в промежутке от 360 до 468
		bill = BASE1 + (RATE2 * (kwh - BREAK1));
	else if (kwh <= BREAK3) //количество кВт/ч в проомежутке от 468 до 720
		bill = BASE2 + (RATE3 * (kwh - BREAK2));
	else  // количество кВт/ч превышает 680
		bill = BASE3 + (RATE4 * (kwh - BREAK3));
	printf("The charge for %.1f kwh is $%1.2f.\r\n", kwh, bill); // Сумма к оплате за % составляет $%
	return 0;
}