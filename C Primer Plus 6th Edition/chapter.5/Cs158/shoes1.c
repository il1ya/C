#include <stdio.h> // преобразует размер обуви в дюймы
#define ADJUST 7.31 // один из видов символической констатнты
int main (void)
{
	const double SCALE = 0.333; // еще один вид символической константы
	double shoe, foot;
	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("Shoe size (male)   foot length\r\n");
	printf("%8.1f %15.2f inches\r\n", shoe, foot);
	return 0;
}