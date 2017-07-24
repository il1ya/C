// ch06ex17.c

/* Chuckie Lucky won a million dollars (after taxes), which he places in an account that earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a program that finds out how many years it takes for Chuckie to empty his account. */

#include <stdio.h>

int main(void)
{
    float base = 1000000;
    float rate = 0.08;
    float sum = base;

    int year = 0;
    while (sum > 0)
    {
        sum = sum * (1 + rate) - 100000;
        year++;
    }

    printf("Lucky can empty his account after %d years.", year);

    getch();
    return 0;
}