/*Давайте протестируем функцию randO() с помощью простого драйвера, показанного в листинге 12.8.*/
// Листинг 12.8. Драйвер r_drive0.c
/*r_drive0 -- тестирование функции randO()*/
/*компилировать вместе с randO.c*/
#include <stdio.h>
extern int randO(void);
int main(void)
{
	int count;
	for(count = 0; count < 5; count++)
		printf("%d\r\n", randO());
	return 0;
}