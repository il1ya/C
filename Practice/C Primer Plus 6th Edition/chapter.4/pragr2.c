#include <stdio.h>
int main (void)
{
	float a, b;
	printf("Enter the number ");
	scanf("%f%f", &a, &b);
	printf("Ur number %2.2f \r\n%.2e", a, b);
	return 0;
}