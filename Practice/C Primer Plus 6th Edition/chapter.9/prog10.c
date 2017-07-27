/* Обобщите функцию to_binary() из листинга 9.8 до функции to_base_n(), которая принимает второй аргумент в диапазоне от 2 до 10. 
Она должна выводить число, переданное в первом аргументе, в системе счисления с основанием, которое указано во втором аргументе. 
Например, вызов to_base_n(129,8) должен отобразить 201, т.е. восьмеричный эквивалент числа 129. Протестируйте готовую функциюв какой-нибудь программе.*/
#include <stdio.h>
// binary.c -- выводит целые числа в двоичной форме + принимает второй аргумент в диапазоне от 2 до 10.

#include <stdio.h>
void to_binary(unsigned long, unsigned int);
int main (void)
{
	unsigned long number;
	unsigned int base;
	printf("Enter an integer and the base(from 2 to 16) to convert (q to quit):\r\n"); // Введите целое число и аргумент в  (# для завершения)
	while(scanf("%lu %u", &number, base) == 2)
	{
		printf("Binary equivalent and the base: "); // Двоичный эквалент:
		to_binary(number, base);
		putchar('\n');
		printf("Enter an integer and the base(from 2 to 16) to convert (q to quit):\r\n"); // Введите целое число (# для завершения)
	}
	printf("Done.\r\n");
	return 0;
}
void to_binary(unsigned long n, unsigned int base) // рекурсивная функция
{
	int r;
	r = n % base;
	if(n >= base)
	{
		to_binary(n / base, base);
	}
	if(r >= 0 && r <= 9)
	{
		putchar('0' + r);
	}
	else if(r >= 10 && r <= 15)
	{
		putchar('A' + r - 10);
	}
	else
	{
		printf("Error base!");
	}
}

/*
Функция to_binary() должна отображать символ 'О’, если числовое значение переменной r равно О, и '1' , если оно равно 1. 
Условное выражение r == О ? 'О' : '1' обеспечивает такое преобразование числовых значений в символьные. 
*/