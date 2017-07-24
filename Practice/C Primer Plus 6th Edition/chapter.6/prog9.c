// Что выведет следующая программа?
#include <stdio.h>
int main (void)
{
	int n, m;
	n = 30;
	while (++n <= 33)
		printf("%d|", n);
	n = 30;
	do
	printf("%d|", n);
	while (++n <= 33);
	printf("\r\n***\r\n");
	for (n = 1; n * n < 200; n += 4)
		printf("%d\r\n", n);
		printf("\r\n***\r\n");
	for (n = 2, m = 6; n < m; n *= 2, m += 2)
		printf("%d %d\r\n", n, m);
		printf("\r\n***\r\n");
	for (n = 5; n > 0; n--)
	{
		for (m = 0; m <= n; m++)
			printf("=");
			printf("\r\n");
	}
	return 0;
}
/*
311321331301311321331
***
1
5
9
13
***
2 6
4 8
8 10
***
======
=====
====
===
==
*/