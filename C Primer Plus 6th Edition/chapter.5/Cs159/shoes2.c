#include <stdio.h> // вычисляет длину стопы для нескольких размеров обуви
#define ADJUST 7.31 // один из видов символической константы
int main (void)
{
	const double SCALE = 0.333; // еще один вид символической константы
	double shoe, foot;
	printf("Shoe size (male)   foot length\r\n");
	shoe = 3.0;
	while (shoe < 18.5) // начало цикла while
	{					// начало блока
		foot = SCALE * shoe + ADJUST;
		printf("%8.1f %15.2f inches\r\n", shoe, foot);
		shoe = shoe + 1.0;
	}					// конец блока
	printf("If the shoe fits, wear it\r\n");
	return 0;
}