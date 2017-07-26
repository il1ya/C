/*
Модифицируйте программу угадывания чисел из листинга 306, чтобы реализовать более интеллектуальную стратегию угадывания. 
Например, программа может изначально предположить число 50 и запросить, больше ли оно задуманного, меньше его или же это и есть задуманное число. 
Если, скажем, предположение меньше задуманного числа, следующая догадка должна находиться посредине между 50 и 100, т.е. 75. 
Если данное предположение больше задуманного числа, то следующая догадка должна располагаться посредине между 75 и 50 и т.д.
Используя такую стратегию двоичного поиска, программа быстро найдет нравильный ответ, во всяком случае, если пользователь не будет обманывать.
*/
#include <stdio.h>
int main(void)
{
	char response;
	int hi = 100;
	int lo = 1;
	int guess = (hi + lo) / 2;
	printf("Pick an integer from 1 to 100. I will tye to quess "); // Виберите целое число в интервале от 1 до 100. Я попробую угадать
	printf("it.\r\nRespond with a y if my quess is right and with"); // Нажмите клавишу y, если моя догадка верна и
	printf("an n if it is wrong.\r\n");// клавишу n в противном случае.
	printf("Uh...is your number %d?\r\n", guess); // Вашим числом является
	while((response = getchar()) != 'y') // получить ответ, сравнить c y
	{
		if(response == '\n')
		continue;
			if(response != 'h' && response != 'l')
			{
			printf("Invalid response. Must type l, h, or y.\r\n");
			continue;
			}
		if(response == 'h')
			hi = guess - 1;
		else if(response == 'l')
			lo = guess + 1;
			guess = (hi + lo) / 2;
		printf("Well, is it %d?\r\n", guess);
	}
	printf("I knew i could do it!\r\n"); // Я знал, что у меня получится!
	return 0;
}