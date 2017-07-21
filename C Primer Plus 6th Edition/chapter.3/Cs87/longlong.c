#include <stdio.h>
int main (void)
{
	unsigned int un = 300000000; // система с 32- битным типом int
	short end = 200;			 // и 16-битным типом short
	long big = 655537;
	long long verybig = 12345678908642;
	printf("un = %u, but not %d\r\n", un, un); // префиксы h and l можно использовать в 8 и 16 форме.
	printf("end = %hd and %d\r\n", end, end); // %hd отображает целое значение short.
	printf("big = %ld, but not %hd", big, big); // %ld выводим значение long.
	printf("\r\nverybig = %lld, but not %ld\r\n", verybig, verybig); // %lld для вывода long long
	return 0;
}