/*
программа должна пропускать любые символы новой строки или пробелы между последним числом, набранным в одном цикле ввода, и первым символом, набираемым в следующей строке. 
Кроме того, было бы неплохо, если бы в дополнение к проверке getchar() программу можно было прекратить на стадии выполнения функции scanf(). 
Все это реализовано в следующей версии программы, показанной в листинге программы showchar2.c
*/
// showchar2.c -- выводит символы в строках и столбцах
#include <stdio.h>
void display(char cr, int lines, int width);
int main(void)
{
	int ch; // выводимый символ
	int rows, cols; // количество строк и столбцов
	printf("Enter a character and two integers:\r\n"); // Введите символ и два целых числа
	while((ch = getchar()) != '\n')
	{
		if(scanf("%d %d", &rows, &cols) != 2)
			break;
		display(ch, rows, cols);
		while(getchar() != '\n')
			continue;
		printf("Enter another character and two integers;\r\n"); // Введите еще один символ и два целых числа
		printf("Enter a newline to quit.\r\n"); // для завершения введите символ новой строки
	}
	printf("Bye.\r\n"); // программа завершена
	return 0;
}
void display(char cr, int lines, int width)
{
	int row, col;
	for(row = 1; row <= lines; row++)
	{
		for(col = 1; col <= width; col++)
			putchar(cr);
		putchar('\n'); // закончить строку и нчать новую
	}
}
/*
Оператор while заставляет программу пропускать все символы, следующие за вводом scanf(), включая символ новой суноки. 
Это подготавливает цикл для чтения первого символа в начале следующей строки. Другими словами, данные можно вводить без ограничений
*/ 
