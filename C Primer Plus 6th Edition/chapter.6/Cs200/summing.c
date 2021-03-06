// сумирует целые числа, вводимые в интерактивном режиме
#include <stdio.h>
int main (void)
{
	long num;
	long sum = 0L; // инициализация переменной sum нулем
	int status;
	printf("Please enter an integer to be summed "); // Введите целое число для последующего суммирования
	printf("(q to quit): "); // или q для завершения программы
	status = scanf("%ld", &num);
	while (status == 1) // == обозначает равенство
		{
			sum = sum + num;
			printf("Please enter next integer (q to quit): "); // Введите следующее целое число (или q для завершения программы)
			status = scanf("%ld", &num);
		}
		printf("Those integers sum to %ld.\r\n", sum); // Сумма введенных целых чисел равна
		return 0;
		/* псевдокод программы
		инициализировать переменную sum значением 0
		выдать пользователю приглашение на ввод
		прочитать входные данные
		пока входное значение представляет собой целое число,
			добавить входное значение и значению sum,
			выдать пользователю приглашение на ввод,
			затем прочитать следующий ввод
		по завершении ввода вывести значение переменной sum 
		*/
}