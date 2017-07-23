/*Напишите программу, которая запрашивает ввод числа типа double и выводит
значение куба этого числа. Для этого используйте собственную функцию,
которая возводит значение в куб и выводит полученный результат. Программа
main () должна передавать этой функции вводимое значение.*/
#include <stdio.h>
int main (void)
{
	double enter; 
	double cube2;
	printf("Enter number\r\n");
	scanf("%lf", &enter);
	cube2 = enter * enter * enter;
	printf("cube = %.4f, enter = %.4f", cube2, enter);
	return 0;
}