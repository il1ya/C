/* Напишите программу, которая запрашивает у пользователя ввод значения высоты
в сантиметрах, после чего отображает высоту в сантиметрах, а также в фу-
и дюймах. Должны быть разрешены дробные части сантиметров и дюймов.
Программа должна позволить пользователю продолжать ввод значений высоты
до тех пор, пока не будет введено неположительное значение. 
Вывод этой программы должен иметь следующий вид:
Введите высоту в сантиметрах: 182
182. О см = 5 футов, 11.7 дюймов
Введите высоту в сантиметрах (<=О для выхода из программы) : 168.7
168.0 см = 5 футов, 6.4 дюймов
Введите высоту в сантиметрах (<=О для выхода из программы) : О
Работа завершена. */
#include <stdio.h>
const float FOOT = 30.48;
const float INCHES = 12;
int main (void)
{
	float centi, decision, inches;
	char name[10];
	printf("Welcom to the translation heights program\r\nWrite your name\r\n");
	scanf("\r\n%s", name);
	printf("\r\n%s enter the height in centimeters: ", name);
	while (centi > 0)
	{
		scanf("%f", &centi);
		decision = centi / FOOT;
		inches = centi / INCHES;
		printf("\r\n%3.1f sm = %1.f feet, %2.1f inch\r\n", centi, decision, inches);
		printf("\r\n%s enter the height in centimeters (enter 0 to exit the program)\r\n", name);
	}
	printf("\r\nWork end, see you next time %s\r\n", name);
	return 0;
}