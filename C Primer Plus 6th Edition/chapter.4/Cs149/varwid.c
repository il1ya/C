#include <stdio.h> // использование поля вывода переменной ширины
int main (void)
{
	unsigned width, precision;
	int number = 256;
	double weight = 242.5;
	printf("Enter the width of the field\r\n"); // Введите ширину поля
	scanf("%d", &width);
	printf("The value is: %*d\r\n", width, number); // Значение равно:
	printf("Now enter the width and precision:\r\n"); // Теперь введите ширину и точность:
	scanf("%d %d", &width, &precision);
	printf("Weight = %*.*f\r\n", width, precision, weight); // Вес =
	printf("Done!\r\n"); // Готово!
	return 0;
}