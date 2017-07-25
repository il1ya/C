/*
Напишите программу, которая читает целые числа до тех пор, пока не встретится число 0. 
После прекращения ввода программа должна сообщить общее количество введенных четных целых чисел (за исключением 0), среднее значение введенных четных целых чисел, 
общее количество введенных нечетных целых чисел и среднее значение нечетных чисел.
*/
#include <stdio.h>
#define STOP 0
int main(void)
{
	int a;
	int b = 0;
	int c = 0;
	double abi = 0.0;
	double abibi = 0.0;
	printf("Enter integer to be analyzed (0 to terminate):\r\n");
	while(scanf("%d", &a) == 1 && a != STOP)
	{
		if(a % 2 == 0)
		{
			abi += a;
			++b;
		}
		else 
		{
			abibi += a;
			++c;
		}
	}
	printf("# of evens: %d", abi);
	if(abi > 0)
	printf(" average: %g", abi / b);
	putchar('\n');
	printf("# of odds: %d", abibi);
	if(abibi > 0)
	printf(" average: %g", abibi / c);
	putchar('\n');
	printf("\r\ndone\r\n");
	return 0;
}