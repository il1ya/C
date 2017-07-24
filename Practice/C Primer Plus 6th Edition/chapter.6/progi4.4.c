#include <stdio.h>
int main (void)
{
	const char a = 'U';
	char b, c;
	char d = 'A';
	for (b = d; d <= a; b++)
	{
		for(c = 'A'; c <= b; c++)
		{
		printf("%c", d);
		d++;
		}
		printf("\r\n");
	}
	return 0;
}