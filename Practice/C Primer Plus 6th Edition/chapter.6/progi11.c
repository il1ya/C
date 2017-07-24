#include <stdio.h>
int main (void)
{
	const int SIZE = 8;
	int i, tate[SIZE];
	printf("Enter 8 integer values separated by spaces:\r\n");
	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &tate[i]);
	}
	for(i = SIZE - 1; i >= 0; i--)
	{
		printf("%d", tate[i]);
	}
	return 0;
}