// ch06ex08.c

/* Write a program that requests two floating-point numbers & prints the value of their difference divided by their product. Have the program loop through pairs of input values until the user enters non-numeric input. */

#include <stdio.h>

int main(void)
{
 	double n1, n2;
 	double result;

 	printf("Enter two floating-point numbers: ");

 	while (scanf("%lf %lf", &n1, &n2) == 2)
 		{
 			result = (n1 - n2) / (n1 * n2);
 			printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n", n1, n2, n1, n2, result);
 			printf("Enter two floating-point numbers (non-numeric value to quit): ");
 		}
 
 	getch();
 	return 0;
}