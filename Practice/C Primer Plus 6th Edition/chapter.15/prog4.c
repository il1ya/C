/*4. 
Напишите функцию, которая принимает два аргумента типа int:  значение и позицию бита. 
Функция должна возвращать 1, если бит в этой позиции равен 1, и 0 в противном случае. 
Протестируйте функциюв какой-нибудь программе.*/
#include <stdio.h>
int bitt(int num, int bit);
int main(void)
{
	int num, bit;
	puts("Please enter an integer: ");
	scanf("%d", &num);
	puts("Please enter the bit you want to check: ");
	scanf("%d", &bit);
	printf("%d\r\n", bitt(num, bit));
	return 0;
}
int bitt(int num, int bit)
{
	int mask = 1;
	mask <<= bit;
	return(num & mask);
}