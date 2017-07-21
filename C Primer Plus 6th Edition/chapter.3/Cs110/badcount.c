#include <stdio.h>
int main (void)
{
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;
	printf("%d\r\n", n);
	printf("%d %d %f\r\n", n, m, f);
	printf("%f %f", f, g);
	return 0;
}