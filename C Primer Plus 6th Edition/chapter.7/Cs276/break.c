/*
Программа, содержит цикл для вычисления длощади прямоугольника. 
Цикл прекращается при вводе нечислового значения для длины или ширины прямоугольника.
*/
// использование оператора break для выхода из цикла
#include <stdio.h>
int main(void)
{
	float length, width;
	printf("Enter the lenght of the rectangle:\r\n"); // Введите длину прямоугольника
	while(scanf("%f", &length) == 1)
	{
		printf("Lenght = %0.2f:\r\n", length); // Длинa
		printf("Enter its width:\r\n"); // Введите ширину прямоугольника
		if(scanf("%f", &width) != 1)
			break;
		printf("Width = %0.2f:\r\n", width); // Щирина
		printf("Area = %0.2f:\r\n", length * width); // Площадь
		printf("Enter the length of the rectangle:\r\n"); // Введите длину прямоугольника
	}
	printf("Done.\r\n"); // Программа завершена
	return 0;
}