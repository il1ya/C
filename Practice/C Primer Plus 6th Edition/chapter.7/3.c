// ch07ex03.c

/* Write a program that reads integers until 0 is entered. After input terminates, the program should report the total number of even integers (excluding the 0) entered, the average value of the even integers, the total number of odd integers entered, & the average value of the odd integers. */

#include <stdio.h>
#define STOP 0
int main(void)
{
    int n;
    int eCount = 0;
    int oCount = 0;
    double eSum = 0.0;
    double oSum = 0.0;
	printf("Enter integer to be analyzed (0 to terminate):\n");
	while (scanf("%d", &n) == 1 && n != STOP)
	{
        if (n % 2 == 0)
        {
            eSum += n;
            ++eCount;
        }
        else
        {
            oSum += n;
            ++oCount;
        }
	}
    printf("# of evens: %d", eCount);
    if (eCount > 0)
        printf(" average: %g", eSum / eCount);
    putchar('\n');

    printf("# of odds: %d", oCount);
    if (oCount > 0)
        printf(" average: %g", oSum / oCount);
    putchar('\n');
    printf("\ndone\n");
	getch();
	return 0;
}