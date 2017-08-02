/*Давайте рассмотрим еще один пример. 
На этот раз цель заключается в том, чтобы
написать функцию, которая инвертирует последние n битов в значении, принимая в качестве аргументов n и само значение.
Операция ~ инвертирует биты, но делает это со всеми битами в байте, а не только с избранными. 
Однако, как вы уже видели, для переключения отдельных битов можно использовать операцию ^ (исключающее “ИЛИ”). 
Предположим, что создана маска, в которой последние n битов установлены в 1, а остальные — в 0. 
Тогда применение ^ к этой маске и значению переключает, или инвертирует, последние n битов, оставляя остальные биты без изменений. 
Такой подход реализован в следующем фрагменте кода:
int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;

	while(bits-- > 0)
	{
		mask |= bitval; побитовая операция ИЛИ
		bitval <<= 1; сдвиг влево
	}
	return num ^ mask;
}

Маска создается в цикле while. Изначально в mask все биты установлены в 0. 
На первой итерации цикла бит 0 устанавливается в 1, после чего значение bitval увеличивается до 2, т.е. в нем бит 0 устанавливается в 0, а бит 1 — в 1. 
На следующей итерации бит 1 в mask устанавливается в 1 и т.д. 
В конце концов, операция num ^ mask дает желаемый результат.
Для тестирования функции ее можно внедрить в предыдущую программу, как показано в листинге 15.2.*/
//Листинг 15.2. Программа invert4.с
/*invert4.c -- использование операций с битами для отображения двоичного представления чисел*/

#include <stdio.h>
#include <limits.h>

char *itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(void)
{
	char bin_str[CHAR_BIT *sizeof(int) + 1];
	int number;
	puts("Enter integers and see them in binary."); // Вводите целые числа и просматривайте их двоичные представления.
	puts("Non-numeric input terminates program."); // Нечисловой ввод завершает программу.
	while(scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d ",number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Inverting the last 4 bits gives\r\n"); // инвертирование последних 4 битов дает
		show_bstr(itobs(number, bin_str));
		putchar('\n');
	}
	puts("Bye!");
	return 0;
}
char *itobs(int n, char *ps)
{
	int i;
	const static int size = CHAR_BIT *sizeof(int);
	for(i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	return ps;
}
/*отображение двоичной строки блоками по 4*/
void show_bstr(const char *str)
{
	int i = 0;
	while(str[i]) /*пока не будет получен нулевой символ*/
	{
		putchar(str[i]);
		if(++i % 4 == 0 && str[i])
			putchar(' ');
	}
}
int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;
	while(bits-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}
	return num ^ mask;
}