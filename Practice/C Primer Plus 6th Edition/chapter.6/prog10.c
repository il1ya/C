// ch06ex10.c
/* 
Write a program that requests lower & upper integer limits, calculates the sum of all the integer squares from the square of the lower limit to the square of the upper limit, & displays the answer. The program should then continue to prompt for limits & display answers until the user enters an upper limit that is equal to or less than the lower limit. A sample run should look something like this:
Enter lower & upper integer limits: 5 9
The sums of the squares from 25 to 81 is 255.
Enter next set of limits: 3 25
The sums of the squares from 9 to 625 is 5520.
Enter next set of limits: 5 5
Done. 
*/
#include <stdio.h>
#include <math.h>
int calc(int, int);
int main(void)
{
    int lower, upper, result;
    printf("Enter lower and upper integer limits: ");
    while (scanf("%d%d", &lower, &upper) == 2 && lower < upper)
    {
        printf("The sums of the squares from %d to %d is %d\r\n", pow(lower, 2), pow(upper, 2), calc(lower, upper));
        printf("Enter lower and upper integer limits: ");
    }
    return 0;
}
int calc(int m, int n)
{
    int sum;
    int i;
    for (i = m; i <= n; i++)
    {
        sum += pow(i, 2);
    }
    return sum;
}