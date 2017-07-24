/*Вложенный цикл — это цикл внутри другого цикла. Вложенные циклы часто используются
для отображения данных в виде строк и столбцов. Один цикл может обрабатывать,
скажем, все столбцы в строке, а второй цикл - все строки. В листинге 6.17
нриведен простой пример. */

// применение вложенных циклов
#include <stdio.h>
#define ROWS 6
#define CHARS 10
int main (void)
{
	int row;
	char ch;
	for (row = 0; row < ROWS; row++) // строка 10 внешний цикл
	{
		for (ch = 'A'; ch < ('A' + CHARS); ch++) // строка 12 внутриний цикл
			printf("%c", ch);
		printf("\r\n");
	}
	return 0;
}
/*
Цикл for, который начинается в строке 10, называется внешним, а цикл, начинающийся в строке 12 — внутренним. 
Внешний цикл стартует при значении О переменной row и завершается, когда ее значение достигает 6. 
Таким образом, происходит шесть итераций внешнего цикла, и переменная row последовательно получает значения от О до 5. 
Первый оператор в каждой итерации является внутренним циклом for. 
Он выполняет 10 итераций, выводя символы от А до J в одной строке. 
Второй оператор внешнего цикла, printf("\n");, 
начинает новую строку, так что при следующем выполнении внутреннего цикла вывод будет производиться в новой строке.
Будучи вложенным циклом, внутренний цикл проходит через полный диапазон итераций для каждой итерации внешнего цикла. 
В последнем примере внутренний цикл выводит 10 символов в строке, а внешний цикл создает 6 таких строк.
*/ 