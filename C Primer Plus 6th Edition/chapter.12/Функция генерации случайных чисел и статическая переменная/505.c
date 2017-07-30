/*Обратите внимание, что next — это статическая переменная с областью видимости в пределах файла и внутренним связыванием. 
Это означает, что она может использоваться как randl(), так и srandl(), но не функциями в других файлах. 
Для тестирования этих функций применяйте драйвер из листинга 12.10.*/
// Листинг 12.10. Драйвер r_drive1.c
/*r_drive1.c -- тестирование функций randl() и srandl()*/
/*компилировать вместе с s_and_r.c*/
#include <stdio.h>
extern void srand1(unsigned int x);
extern int randl(void);
int main(void)
{
	int count;
	unsigned seed;
	printf("Please enter your choice for seed.\r\n"); // Введите желаемое начальное число.
	while(scanf("%u", &seed) == 1)
	{
		srandl(seed); // переустановка начального числа
		for(count = 0; count < 5; count++)
			printf("%d\r\n", rand1());
		printf("Please enter next seed (q to quit):\r\n"); // Введите следующее начальное число (q для завершения)
	}
	printf("Done\r\n");
	return 0;
}
/*Использование значения 1 для seed выдает те же псевдослучайные числа, что и ранее, но значение 3 для seed обеспечивает выдачу новых результатов.*/