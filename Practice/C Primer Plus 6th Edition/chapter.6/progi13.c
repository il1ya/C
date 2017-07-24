#include <stdio.h>
int main(void)
{
	const int SIZE = 8;
	int a, b[SIZE];
	int c = 1;
	for(a = 0; a < SIZE; a++)
	{
		b[a] = c;
		c *= 2;
	}
	a = 0;
	do
	{
		printf("%d", b[a]);
		a++;
	}while(a < SIZE);
	return 0;
}