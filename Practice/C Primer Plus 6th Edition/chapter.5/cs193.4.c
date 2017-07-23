#include <stdio.h>
int main (void)
{
	int i = 1;
	float n;
	printf("Be careful! Next comes a sequence of fractions!\r\n");
	while (i++ < 30)
	{
		n = 1.0 / i;
		printf("%f", n);
	}
		printf(" end!\r\n");
		return 0;
}