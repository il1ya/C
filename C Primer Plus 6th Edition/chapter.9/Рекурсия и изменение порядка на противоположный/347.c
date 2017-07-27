// binary.c -- выводит целые числа в двоичной форме

#include <stdio.h>
void to_binary(unsigned long n);
int main (void)
{
	unsigned long number;
	printf("Enter an integer (q to quit):\r\n"); // Введите целое число (# для завершения)
	while(scanf("%lu", &number) == 1)
	{
		printf("Binary equivalent: "); // Двоичный эквалент:
		to_binary(number);
		putchar('\n');
		printf("Enter an integer (q to quit):\r\n"); // Введите целое число (# для завершения)
	}
	printf("Done.\r\n");
	return 0;
}
void to_binary(unsigned long n) // рекурсивная функция
{
	int r;
	r = n % 2;
	if(n >= 2)
	to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');
	return;
}

/*
Функция to_binary() должна отображать символ 'О’, если числовое значение переменной r равно О, и '1' , если оно равно 1. 
Условное выражение r == О ? 'О' : '1' обеспечивает такое преобразование числовых значений в символьные.
*/