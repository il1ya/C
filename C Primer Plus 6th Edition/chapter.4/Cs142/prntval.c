#include <stdio.h> // выяснение возвращаемого значения функции printf()
int main (void)
{
	int bph2o = 212;
	int rv;
	rv = printf("Water boils at %d Fahrenheit\r\n", bph2o); // Вода закипает при %d градусах по Фаренгейту
	printf("function printf(); brought %d characters\r\n", rv); // Функция printf(); вывела %d символов
	return 0;
}