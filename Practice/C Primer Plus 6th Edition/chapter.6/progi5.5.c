#include <stdio.h>
int main (void)
{
	const char a = 'A';
	char enter, c, d, b, x;
	printf("Enter");
	scanf("%c", &enter);
	for(c = a; c <= enter; c++)
	{
		for(d = enter; d >= c; d--)
		{
			printf("-");
		}
		for(b = a; b <= c; b++)
		{
			printf("%c", b);
		}
		for(x = b - 2; x >= a; x--)
		{
			printf("%c", x);
		}
		printf("\r\n");

	}
	return 0;
}