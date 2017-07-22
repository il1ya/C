#include <stdio.h>
#define GALLON 3.785
#define MILE 1.609
#define MPG 236 // универсальный коэффициент, равный 236, на количество миль, которое машина проходит на одном галлоне бензина. 
int main (void)
{
	float miles, gallons, calculation, calculation1;
	char name[10];
	printf("Hello enter ur name\r\nEnter the number of miles and the number of gallons spent fuel\r\n");
	scanf("%s %f%f", name, &miles, &gallons);
	calculation = MPG / gallons;
	printf("%s %.1f\r\n", name, calculation);
	calculation1 = MPG / GALLON;
	printf("%.1f\r\n", calculation1);
	return 0;
}