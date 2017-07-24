// ch06ex12.c

/* Consider these two infinite series:
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
Write a program that evaluates running totals of these two series up to some limit of number of terms. Hint: -1 times itself an odd number of times is -1, & -1 times an even number of times is 1. Have the user enter the limit interactively; let a zero or negative value terminate input. Look at the running totals after 100 terms, 1000 terms, 10,000 terms. Does either series appear to be converging to some value? */

#include <stdio.h>
#include <math.h>
int calc(int);
int main(void)
{
	int limit;
	double down, up;
    printf("Enter a limit integer: ");
    while (scanf("%d", &limit) == 1)
    {
        printf("Up: %g Down: %g\n", calc(limit), calc(limit));
        printf("Enter a limit integer: ");
    }
    return 0;
}

int calc(int limit)
{
    double up = 0, down = 0;
    double i;
	
    for (i = 1; i <= limit; i++)
    {
        up = up + 1.0 / i;
        down = down + (1.0 / i) * pow(-1, i) * (-1);
    }
    return up;
}