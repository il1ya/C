#include <stdio.h>

int main (void)
{
	long long i = 214766;
	unsigned long j = 429466;
	printf("%d %d %d\r\n", i, i + j, j + 2);
	printf("%u %u %u\r\n", j, j + i, j + 2); // для отображения значения типа unsigned int применяется спецификатор %u
	return 0;
}