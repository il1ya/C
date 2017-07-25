// вложенные операторы if отображают делители числа
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	unsigned long num;    // проверяемое число
	unsigned long div; 	  // потенциальные делители
	bool isPrime;		  // флаг простого числа
	printf("Please enter an integer for analysis; ");
	printf("Enter q to quit.\r\n");
	while (scanf("%lu", &num) == 1)
	{
		for (div = 2, isPrime = true; (div * div) <= num; div++)
		{
			if(num % div == 0)
			{
			if ((div * div) != num)
				printf("%lu is divisible by %lu and %lu.\r\n", num, div, num / div);
			else
				printf("%lu is divisible by %lu.\r\n", num, div);
				isPrime = false; // число не является простым
			}
		}
	if (isPrime)
	printf("%lu is prime.\r\n", num);
	printf("Please enter another integer for analysis; ");
	printf("Enter q to quit.\r\n");
	}
printf("Buy.\r\n");
return 0;
}
/*
Обратите внимание на то, что программа использует операцию запятой в управляющем выражении цикла for, чтобы предоставить вам возможность инициализации переменной 
isPrime значением true при каждом вводе нового числа.
*/ 