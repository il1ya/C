#include <stdio.h>
int main(void)
{
	int div;
	int num = 144;
	for (div = 2; (div * div) <= num; div++)
	{
		if (num % div == 0)
		{
			if (div * div != num)
				printf("%d is divisible by %d and %d.\r\n", num, div, num / div);
			else
				printf("%d is divisible by %d.\r\n", num, div);
		}
	}
	return 0;
}