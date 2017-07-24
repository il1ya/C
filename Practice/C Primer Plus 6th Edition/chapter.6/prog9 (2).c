// ch06ex09.c

// Modify exercise 8 so that it uses a function to return the value of the calculation.

#include <stdio.h>

double calc(double, double);

int main(void)
{
 	double n1, n2, result;

 	printf("Enter two floating-point numbers: ");

 	while (scanf("%lf %lf", &n1, &n2) == 2)
 		{
			// A function call that sends two values (n1 & n2) & receives 1 (r --> result).
 			result = calc(n1, n2);
 			printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n", n1, n2, n1, n2, result);
 			printf("Enter two floating-point numbers (non-numeric value to quit): ");
 		}
 
 	getch();
 	return 0;
}

double calc(double m, double n)
{
	double r;
	r = (m - n) / (m * n);
	return r;
}