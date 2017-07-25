#include <stdio.h>
int main(void)
{
	int num = 144;
	int div;
	for (div = 2; (div * div) <= num; div++)
		if (num % div == 0)
			printf("%d is divisible by %d\r\n", num, div);
		return 0;
}