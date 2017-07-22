#include <stdio.h>
#define PI 3.14159
int main (void)
{
	float area, circum, radius;
	printf("What is the range of your pizza?\r\n"); // Каков радиус вашей пиццы?
	scanf("%f", &radius);
	area = PI * radius * radius;
	circum = 2.0 * PI * radius;
	printf("The main parameters of your pizza\r\n"); // Основные параметры вашей пиццы
	printf("circumference = %1.2f area = %1.2f", circum, area); // длина окружности = , площадь = ,
	return 0; 

}