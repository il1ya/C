/*1. Перепшите программу из листинга 12.4 так, чтобы в ней не использовались глобальные переменные.*/
#include <stdio.h>
// int units = 0; // внешняя переменная
void critic(void);
int main(void)
{
	int units = 0;
	// extern int units; // необязательное повторное объявление
	printf("How many pounds to a firkin of butter?\r\n"); // Сколько фунтов весит маленький бочонок масла?
	scanf("%d", &units);
	while(units != 56)
		critic();
	printf("You must have looked it up!\r\n"); // Вы знали это!
	return 0;
}
void critic(void)
{
	int units = 0;
	// необязательное повторное объявление опущено
	printf("No luck, my friend. Try again.\r\n"); // Вам не повезло. Попробуйте еще раз
	scanf("%d", &units);
} 