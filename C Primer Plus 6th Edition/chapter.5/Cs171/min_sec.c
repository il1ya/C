// переводит секунды в минуты и секунды
#include <stdio.h>
#define SEC_PER_MIN 60 // количество секунд в минуте
int main (void)
{
	int sec, min, left;
	printf("Translation seconds to minutes and seconds!\r\n"); // Перевод секунд в минуты и секунды!
	printf("Enter the number of seconds (< = 0 to exit):\r\n"); // введите количество секунд
	scanf("%d", &sec); // чтение количества секунд
	while (sec > 0) // начало цикла while
	{
		min = sec / SEC_PER_MIN; // усеченное количество минут
		left = sec % SEC_PER_MIN; // количество секунд в остатке
		printf("%d seconds - this %d minutes %d seconds\r\n", sec, min, left);
		printf("Enter next value (< = 0 to exit):\r\n"); // < = 0 для выхода.
		scanf("%d", &sec);
	} 
	printf("Ready!\r\n");
	return 0;
}