/*Напишите и протестируйте функцию Fibonacci(), в которой для вычисления чисел Фибоначчи вместо рекурсии применяется цикл.*/
#include <stdio.h>
unsigned long Fibonacci(unsigned int);
int main(void)
{
	unsigned int enter1;
	printf("This program returns the corresponding Fibonacci number.\r\n");
	printf("Enter your integer: ");
	while(scanf("%u", enter1) == 1)
	{
		printf("Fibonacci(%u) = %lu\r\n", enter1, Fibonacci(enter1));
		printf("Enter your integer: ");
	}
	return 0;
}
unsigned long Fibonacci(unsigned int n)
{
	unsigned long n_1 = 0, n_2 = 0, ret = 0;
	unsigned int i = 0;
	if(n <= 2)
	{
		return 1;
	}
	else
	{
		n_1 = 1;
		n_2 = 2;
		for(i = 3; i <= n; i++)
		{
			ret = n_1 + n_2;
			n_1 = n_2;
			n_2 = ret;
		}
		return ret;
	}
}