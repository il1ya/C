#include <stdio.h>
int main (void)
{
	float weight; // вес пользователя
	float value; // платиновый эквивалент
	printf("Want to know your weight in platinum equivalent? \r\n");
	printf("Let's count.\r\n");
	printf("Enter your weight in pounds: ");
	

// получить входные данные от пользователя

	scanf("%f", &weight);

	// считаем, что цена родия равна $1700 за тройскую унцию
	// 14.5833 коэффициент для перевода веса, выраженного в фунтах, в тройские унции
	value = 1700.0 * weight * 14.5833;
	printf("Your weight in platinum equivalent of $%.2f.\r\n", value);
	printf("You can easily become worthy of it! If the platinum price falls\r\n");
	printf("eat more to maintain their value.\r\n");
	return 0;
}