#include <stdio.h>
int main (void)
{
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f It can be written as %e\n", aboat, aboat);
	// для вывода следущей строки требуется компилятор,
	// поддерживающий С99 или более поздний стандарт
	printf("And %a in 16, representing the power of 2, the form of recording\n", aboat);
	printf("%f It can be written as %e\n", abet, abet);
	printf("%Lf It can be written as %Le\n", dip, dip);
	return 0;
}