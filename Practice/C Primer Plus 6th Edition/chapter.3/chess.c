#include <stdio.h>
int main (void)
{
	int a, b, d;
	a = b = d = 165;
	int go;
	printf("  a   b   d\r\n");
	printf("%4d %d %d ", a, b, d);
	printf("Go___\b\b\b");
	scanf("%d", &go);
	printf("\rend %d %d", go * 2 + 20);
	return 0;
}